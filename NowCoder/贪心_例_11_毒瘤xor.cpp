#include<iostream>
#include<vector> 
using namespace std;
// 32 可以改为 31

void solve()
{ 
    int n;
    cin >> n;
    
    vector<vector<int>> dp(n+1,vector<int>(32,0));
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        for(int j=0;j<32;j++)
        {
            if(a[i]&(1<<j))
            {
                dp[i+1][j]=dp[i][j]+1;
            }
            else
            {
                dp[i+1][j]=dp[i][j];
            }
        }
    }
    int q;
    cin>>q;

    while(q--){
        vector<int> b(32,0);
        int l,r;
        cin>>l>>r;
        int len=r-l+1;
        for(int i=0;i<32;i++)
        {
            b[i]=dp[r][i]-dp[l-1][i];
        }
        int ans=0; 
        for(int i=0;i<31;i++)
        {
            if(2*b[i]<len)
            {
                ans|=(1<<i);
            }
        }
        cout<<ans<<endl;
    }

}

int main()
{
    solve();
    return 0;
}