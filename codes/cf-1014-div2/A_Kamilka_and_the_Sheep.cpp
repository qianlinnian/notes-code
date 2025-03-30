#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> an(n);
        for(int i=0;i<n;i++)
        {
            cin>>an[i];
        }
        sort(an.begin(),an.end());
        cout<<an[n-1]-an[0]<<endl;

    }
    return 0;
}