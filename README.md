算法刷题笔记

## CPH 题目自动分类

Competitive Companion 把题目发送给 CPH 后，`tools/organize-cph.ps1` 会读取 `.prob` 中的题目 URL，并把工作区根目录新生成的源码移动到对应来源目录：

- `Codeforces`
- `NowCoder`
- `LeetCode`（沿用已有目录）
- `Matiji`
- `AtCoder`
- `Luogu`
- `Other`

同时会移动并更新 CPH 的 `.prob` 测试数据，因此整理后的源码仍可使用 CPH 运行样例。脚本只处理工作区根目录的新源码，不会移动已经整理好的文件，也不会覆盖同名文件。

VS Code 打开本工作区时会启动任务 `CPH: 自动按来源整理（监听）`。首次使用时，VS Code 可能会询问是否允许自动任务，选择允许即可。

也可以通过“终端 → 运行任务”手动运行：

- `CPH: 按来源整理（一次）`
- `CPH: 自动按来源整理（监听）`

命令行预览但不移动文件：

```powershell
powershell.exe -NoProfile -ExecutionPolicy Bypass -File .\tools\organize-cph.ps1 -DryRun
```

