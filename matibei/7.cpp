#include<iostream>
#include<vector>

using namespace std;
const long long Mode=998244353;
int main()
{
    // 使用逆序对
    int n;
    cin >> n;
    vector<long long> a(n),sumone(n,0);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if(a[0]==1)
    {
        sumone[0]=1;
    }
    long long ans=0; // 1-based index
    for(int i = 1; i < n; i++)
    {
        if(a[i]==0)
        {
            sumone[i]=sumone[i-1];
            ans+=(ans + sumone[i] * (n-i) % Mode)%Mode;
        }
        else if(a[i]==1)
        {
            sumone[i]=(sumone[i-1]+i+1)%Mode; // sumoen is the sumo of positions of 1s
        }
    }
    cout << ans << endl;
    return 0;
}