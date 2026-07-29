#include<iostream>
#include<vector>
#include<limits>
#include<algorithm>
#include<climits>
using namespace std; 
vector<long long> v;
vector<long long> prefix;
struct Point {
    long long x;
    long long y;
};
vector<Point> P;
long long distance2(const Point& a, const Point& b)
{
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;

    return dx * dx + dy * dy;
}
const bool cmpy(const Point& a, const Point& b)
{
    if (a.y != b.y) {
        return a.y < b.y;
    }

    return a.x < b.x;

}
// 分治
long long solve(int l,int r){
    if(l==r-1)
    {
        return distance2(P[l], P[l+1]);
    }
    else if (l==r)
    {
        return LONG_LONG_MAX;
    }
    int mid = (l+r)/2;
    // 先是左右递归，求 两边的最小距离
    long long d1=solve(l, mid);
    long long d2=solve(mid+1, r);
    long long d = min(d1, d2);

    // 处理不同侧的 点的距离：
    vector<Point> strip; 
    // 创建空组，记录当前区间中靠近中线的点
    for(int i=l;i<=r;i++)
    {
        long long dx=abs(P[i].x-P[mid].x);
        if(dx*dx<d)
        {
            strip.push_back(P[i]);
        }
    }
    sort(strip.begin(), strip.end(), cmpy);
    // 按照y坐标排序 如果 y相同，按照 x坐标排序
    //检查跨越中点的点对

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size(); j++) {
            long long dy = strip[j].y - strip[i].y;

            if (dy * dy >= d) {
                break;
            }

            d = min(d, distance2(strip[i], strip[j]));
        }
    }

    return d;
}

int main()
{
    int n;
    cin>>n;
    v.resize(n);
    prefix.resize(n+1, 0);

    for(int i=0;i<n;i++){
        cin>>v[i];
        prefix[i+1] = prefix[i] + v[i];
        P.push_back({i, prefix[i+1]});
    }
    //f is the distance^2 of the two points 
    long long f = LONG_LONG_MAX;
    f=solve(0, n-1);
    cout<<f<<endl;




    return 0;
}