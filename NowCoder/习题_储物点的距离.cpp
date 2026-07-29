#include<iostream>
#include<vector>
using namespace std;
const int Mode=1000000007;
 
void solve()
{
    int n,m;
    cin>>n>>m;

    vector<long long> a(n); 
    a[0]=0;
    for(int i=1;i<n;i++)
    {
        cin>>a[i];//第i个存储点到 i+1存储点的距离
    }
    vector<long long> b(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];//第i个存储点的物品数量
    }

    vector<long long> pos(n+1,0);
    vector<long long> sumb(n+1,0);
    vector<long long> sumc(n+1,0);

    for(int i=1;i<=n;i++)
    {
        pos[i]=(pos[i-1]+a[i-1])%Mode;
        sumb[i]=(sumb[i-1]+b[i])%Mode;
        sumc[i]=(sumc[i-1]+b[i]*pos[i])%Mode;
    }
    while(m--)
    {
        int x,l,r;
        cin>>x>>l>>r;
        long long ans=0;
        
        if(r<=x)
        {
            ans=(ans+pos[x]*(sumb[r]-sumb[l-1])-(sumc[r]-sumc[l-1]))%Mode;
        }
        else if(l>=x)
        {
            ans=(ans+(sumc[r]-sumc[l-1])-(sumb[r]-sumb[l-1])*pos[x])%Mode;
        }
        else
        {
            ans=(ans+pos[x]*(sumb[x]-sumb[l-1])-(sumc[x]-sumc[l-1]))%Mode;
            ans=(ans+(sumc[r]-sumc[x])-(sumb[r]-sumb[x])*pos[x])%Mode;
        }
        
        ans = (ans % Mode + Mode) % Mode;
        cout << ans << '\n';
    }
}

int main()
{
    solve();
    return 0;
}