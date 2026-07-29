# include<iostream> 
using namespace std; 

// 为了避免溢出，需要对 10 进行取模
long long qpow(long long a,long long b)
{
    long long res=1;
    while(b)
    {
        if(b&1) res=res*a%10;
        a=a*a%10;
        b>>=1;
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    long long cnt2=0,cnt5=0;
    long long res=1;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin>>num; 
        while(num%2==0)
        {
            num/=2;
            cnt2++;
        }
        while(num%5==0)
        {
            num/=5;
            cnt5++;
        }
        res= res*(num%10)%10;
    }
 
    long long min_cnt = min(cnt2, cnt5);
    cnt2 -= min_cnt;
    cnt5 -= min_cnt; 
    if(cnt2) res=res * qpow(2, cnt2) % 10;
    if(cnt5) res=res * qpow(5, cnt5) % 10;


    cout<<res<<endl;


    return 0;
}