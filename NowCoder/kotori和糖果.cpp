#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unistd.h>
using namespace std;

// 类似于树状结构 
// 两侧要均衡
unordered_map<long long,long long> mp;

long long solve(long long n){
    
    if(mp.count(n)) return mp[n];

    long long l=n/2;
    long long r=n-l;
    long long result;
    if(l==r) {
        result=2*solve(r);
    } else {
        result=1+solve(l)+solve(r);
    }
    mp[n]=result;
    return result;

}

int main()
{
    long long T=1e18;
    mp[0]=0;
    mp[1]=0;
    long long mymax=0;
    for(long long i=0;i<T;i++) {
        long long n=i;
        long long ans=0;
        ans=solve(n);
        cout<<n<<' '<<ans<<endl;
        if(ans>mymax) mymax=ans; 
    }
    cout<<"mymax="<<mymax<<endl;
    return 0;
}