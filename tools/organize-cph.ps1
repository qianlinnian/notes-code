[CmdletBinding()]
param(
    [switch]$Watch,
    [switch]$DryRun,
    [int]$PollMilliseconds = 1000,
    [string]$WorkspaceRoot = ''
)

$ErrorActionPreference = 'Stop'
if ([string]::IsNullOrWhiteSpace($WorkspaceRoot)) {
    $WorkspaceRoot = Split-Path -Parent $PSScriptRoot
}
$WorkspaceRoot = [IO.Path]::GetFullPath($WorkspaceRoot).TrimEnd('\', '/')
$InboxDirectory = Join-Path $WorkspaceRoot '.cph'
$Utf8NoBom = New-Object System.Text.UTF8Encoding($false)

function Test-PathInsideWorkspace {
    param([Parameter(Mandatory = $true)][string]$Path)

    $fullPath = [IO.Path]::GetFullPath($Path)
    $prefix = $WorkspaceRoot + [IO.Path]::DirectorySeparatorChar
    return $fullPath.StartsWith($prefix, [StringComparison]::OrdinalIgnoreCase)
}

function Get-PlatformDirectoryName {
    param([Parameter(Mandatory = $true)]$Problem)

    $url = [string]$Problem.url
    $hostName = ''
    if (-not [string]::IsNullOrWhiteSpace($url)) {
        try {
            $hostName = ([Uri]$url).Host.ToLowerInvariant()
        }
        catch {
            $hostName = ''
        }
    }

    switch -Regex ($hostName) {
        '(^|\.)codeforces\.com$'              { return 'Codeforces' }
        '(^|\.)(nowcoder\.com|nowcoder\.cn)$' { return 'NowCoder' }
        '(^|\.)leetcode\.(com|cn)$'           { return 'LeetCode' }
        '(^|\.)matiji\.net$'                  { return 'Matiji' }
        '(^|\.)atcoder\.jp$'                  { return 'AtCoder' }
        '(^|\.)luogu\.com\.cn$'              { return 'Luogu' }
    }

    $group = [string]$Problem.group
    switch -Regex ($group) {
        '^Codeforces\b' { return 'Codeforces' }
        '^NowCoder\b|^牛客' { return 'NowCoder' }
        '^LeetCode\b' { return 'LeetCode' }
        '^码蹄|^Matiji\b' { return 'Matiji' }
        '^AtCoder\b' { return 'AtCoder' }
        '^洛谷|^Luogu\b' { return 'Luogu' }
    }

    return 'Other'
}

function Get-MetadataSourcePath {
    param(
        [Parameter(Mandatory = $true)][string]$DestinationPath,
        [Parameter(Mandatory = $true)][string]$OriginalSourcePath
    )

    $result = [IO.Path]::GetFullPath($DestinationPath)

    # VS Code/CPH often stores a lower-case Windows drive letter. The MD5 name
    # of the .prob file is case-sensitive, so preserve the original style.
    if ($OriginalSourcePath -cmatch '^[a-z]:\\' -and $result -cmatch '^[A-Z]:\\') {
        $result = $result.Substring(0, 1).ToLowerInvariant() + $result.Substring(1)
    }

    return $result
}

function Get-Md5Hex {
    param([Parameter(Mandatory = $true)][string]$Text)

    $md5 = [Security.Cryptography.MD5]::Create()
    try {
        $bytes = [Text.Encoding]::UTF8.GetBytes($Text)
        $hash = $md5.ComputeHash($bytes)
        return -join ($hash | ForEach-Object { $_.ToString('x2') })
    }
    finally {
        $md5.Dispose()
    }
}

function Get-CphProblemPath {
    param([Parameter(Mandatory = $true)][string]$MetadataSourcePath)

    $sourceDirectory = Split-Path -Parent $MetadataSourcePath
    $sourceName = Split-Path -Leaf $MetadataSourcePath
    $hash = Get-Md5Hex -Text $MetadataSourcePath
    return Join-Path (Join-Path $sourceDirectory '.cph') ".${sourceName}_${hash}.prob"
}

function Get-AvailableDestinationPath {
    param(
        [Parameter(Mandatory = $true)][string]$Directory,
        [Parameter(Mandatory = $true)][string]$FileName
    )

    $candidate = Join-Path $Directory $FileName
    if (-not (Test-Path -LiteralPath $candidate)) {
        return $candidate
    }

    $baseName = [IO.Path]::GetFileNameWithoutExtension($FileName)
    $extension = [IO.Path]::GetExtension($FileName)
    for ($index = 2; $index -lt 10000; $index++) {
        $candidate = Join-Path $Directory ("{0}_{1}{2}" -f $baseName, $index, $extension)
        if (-not (Test-Path -LiteralPath $candidate)) {
            return $candidate
        }
    }

    throw "Could not find an unused name for '$FileName' in '$Directory'."
}

function Read-CphProblem {
    param([Parameter(Mandatory = $true)][string]$ProblemFile)

    for ($attempt = 0; $attempt -lt 8; $attempt++) {
        try {
            return Get-Content -Raw -Encoding UTF8 -LiteralPath $ProblemFile | ConvertFrom-Json
        }
        catch {
            if ($attempt -eq 7) {
                throw
            }
            Start-Sleep -Milliseconds 150
        }
    }
}

function Move-CphProblemBySource {
    param([Parameter(Mandatory = $true)][string]$ProblemFile)

    if (-not (Test-Path -LiteralPath $ProblemFile)) {
        return
    }

    try {
        $problem = Read-CphProblem -ProblemFile $ProblemFile
    }
    catch {
        Write-Warning "Cannot read CPH metadata: $ProblemFile ($($_.Exception.Message))"
        return
    }

    $sourcePath = [string]$problem.srcPath
    if ([string]::IsNullOrWhiteSpace($sourcePath) -or -not (Test-Path -LiteralPath $sourcePath)) {
        Write-Verbose "Skip metadata whose source file is missing: $ProblemFile"
        return
    }

    if (-not (Test-PathInsideWorkspace -Path $sourcePath)) {
        Write-Verbose "Skip source outside this workspace: $sourcePath"
        return
    }

    # Competitive Companion creates new files in the workspace root. Restrict
    # moves to that inbox so existing hand-organized files are never disturbed.
    $sourceDirectory = [IO.Path]::GetFullPath((Split-Path -Parent $sourcePath)).TrimEnd('\', '/')
    if (-not $sourceDirectory.Equals($WorkspaceRoot, [StringComparison]::OrdinalIgnoreCase)) {
        Write-Verbose "Already organized or not in the workspace root: $sourcePath"
        return
    }

    $platform = Get-PlatformDirectoryName -Problem $problem
    $destinationDirectory = Join-Path $WorkspaceRoot $platform
    $destinationPath = Get-AvailableDestinationPath -Directory $destinationDirectory -FileName (Split-Path -Leaf $sourcePath)
    $metadataSourcePath = Get-MetadataSourcePath -DestinationPath $destinationPath -OriginalSourcePath $sourcePath
    $destinationProblemFile = Get-CphProblemPath -MetadataSourcePath $metadataSourcePath

    if ($DryRun) {
        Write-Output "[dry-run] $sourcePath -> $destinationPath"
        Write-Output "[dry-run] $ProblemFile -> $destinationProblemFile"
        return
    }

    $destinationCphDirectory = Split-Path -Parent $destinationProblemFile
    New-Item -ItemType Directory -Force -Path $destinationDirectory | Out-Null
    New-Item -ItemType Directory -Force -Path $destinationCphDirectory | Out-Null

    $problem.srcPath = $metadataSourcePath
    $temporaryProblemFile = $destinationProblemFile + '.tmp-' + [Guid]::NewGuid().ToString('N')
    $sourceMoved = $false

    try {
        Move-Item -LiteralPath $sourcePath -Destination $destinationPath
        $sourceMoved = $true

        $json = $problem | ConvertTo-Json -Depth 100 -Compress
        [IO.File]::WriteAllText($temporaryProblemFile, $json, $Utf8NoBom)
        Move-Item -LiteralPath $temporaryProblemFile -Destination $destinationProblemFile

        if (-not ([IO.Path]::GetFullPath($ProblemFile).Equals(
                    [IO.Path]::GetFullPath($destinationProblemFile),
                    [StringComparison]::OrdinalIgnoreCase))) {
            Remove-Item -LiteralPath $ProblemFile
        }

        Write-Output "[$platform] $(Split-Path -Leaf $sourcePath) -> $destinationPath"
    }
    catch {
        if (Test-Path -LiteralPath $temporaryProblemFile) {
            Remove-Item -LiteralPath $temporaryProblemFile -Force
        }
        if ($sourceMoved -and (Test-Path -LiteralPath $destinationPath) -and -not (Test-Path -LiteralPath $sourcePath)) {
            Move-Item -LiteralPath $destinationPath -Destination $sourcePath
        }
        Write-Warning "Failed to organize '$sourcePath': $($_.Exception.Message)"
    }
}

function Invoke-InboxScan {
    if (-not (Test-Path -LiteralPath $InboxDirectory)) {
        return
    }

    Get-ChildItem -LiteralPath $InboxDirectory -Force -File -Filter '*.prob' |
        ForEach-Object { Move-CphProblemBySource -ProblemFile $_.FullName }
}

Invoke-InboxScan

if (-not $Watch) {
    exit 0
}

Write-Output '[cph-organizer] watching'
Write-Output '[cph-organizer] ready'

$knownFiles = @{}
while ($true) {
    if (Test-Path -LiteralPath $InboxDirectory) {
        $currentFiles = Get-ChildItem -LiteralPath $InboxDirectory -Force -File -Filter '*.prob'
        foreach ($file in $currentFiles) {
            $signature = '{0}:{1}' -f $file.Length, $file.LastWriteTimeUtc.Ticks
            if (-not $knownFiles.ContainsKey($file.FullName) -or $knownFiles[$file.FullName] -ne $signature) {
                $knownFiles[$file.FullName] = $signature
                Move-CphProblemBySource -ProblemFile $file.FullName
            }
        }

        foreach ($knownPath in @($knownFiles.Keys)) {
            if (-not (Test-Path -LiteralPath $knownPath)) {
                $knownFiles.Remove($knownPath)
            }
        }
    }

    Start-Sleep -Milliseconds $PollMilliseconds
}
