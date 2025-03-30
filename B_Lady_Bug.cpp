#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1>>s2;
        int even1=0,odd1=0;
        int even0=0,odd0=0;
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='1') {
                num++;
                if(i%2==0)
                {
                    odd1++;
                }
                else
                    even1++;
            }
            if(s2[i]=='1') num++;
            else
            {
                if(i%2==0)
                    odd0++;
                else
                    even0++;
            }
        }
        if(num>n)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(odd0<even1 || even0 < odd1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}