#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main()
{
    int n,m;
    cin>>n>>m;
    int covered=0;// 贪心，维护 covered直到 covered==n
    /* covered 表示当前已经覆盖的区间
        因为当前一个区间都没有覆盖，包括1也没有
        所以 covered 初始化为0 */
    int ans=0;
    int index=0;
    vector<vector<int>> v;
    for(int i=0;i<m;i++) {
        int l,r;
        cin>>l>>r;
        v.push_back({l,r});
    }
    sort(v.begin(),v.end());
    // 默认 按照 第一个元素 第二个元素 比较，
    // 会按照 左端点 升序排列
    while(covered<n) {  
        // covered<n 说明还没有覆盖到 n
        // 如果加上等号，covered==n 说明已经覆盖到 n 了，直接退出循环
        // 在同时如果 index<m 所以，会导致 再次循环，ans+++
        
        // 外层也不必判断 index < m。
        // 即使区间已经用完，也应该进入循环，
        // 然后通过“无法继续扩展”判断失败：
        
        int maxright=covered; // 维护当前覆盖的最右端点
        
        while(index<m && v[index][0]<=covered+1){
            maxright=max(maxright,v[index][1]);
            index++;
        }
        if(maxright==covered && maxright<n) {
            cout<<-1<<endl;
            return 0;
        }
        covered=maxright;
        ans++; 
        
    }
    if(covered<n) {
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
    
}