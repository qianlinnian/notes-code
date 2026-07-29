#include<iostream>
#include<vector>

using namespace std;
struct Point
{
    int x,y;
};

void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    vector<Point> points;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            char c;
            cin >> c;
            grid[i][j]=c;
            if(c=='#')
            {
                Point p;
                p.x=i;
                p.y=j;
                points.push_back(p);
            }
        }
    }
    int size=points.size();
    int maxlen=-1;
    Point p1,p2,p3,p4;
    for(int i=0;i<size;i++)
    {
        Point pa=points[i];
        for(int j=0;j<size;j++)
        {
            if(i==j)
            {
                continue;
            }
            Point pb=points[j];
            int dx=pb.x-pa.x;
            int dy=pb.y-pa.y;
            int len=dx*dx+dy*dy;

            if(len<=maxlen)
            {
                continue;
            }

            Point pc={pa.x-dy,pa.y+dx};
            Point pd={pb.x-dy,pb.y+dx};
            
            if(pc.x<0||pc.x>=n||pc.y<0||pc.y>=n||pd.x<0||pd.x>=n||pd.y<0||pd.y>=n)
            {
                continue; 
            }
            if(grid[pc.x][pc.y]!='#' || grid[pd.x][pd.y]!='#')
            {
                continue;
            }
            
            maxlen=len;// update
            p1=pa;
            p2=pb;
            p3=pc;
            p4=pd;
        }
    }
    cout<<p1.x+1<<" "<<p1.y+1<<endl;
    cout<<p2.x+1<<" "<<p2.y+1<<endl;
    cout<<p3.x+1<<" "<<p3.y+1<<endl;
    cout<<p4.x+1<<" "<<p4.y+1<<endl;

}
int main()
{
    solve();
    return 0;
}