#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std; 
int mid[10][10] = {};


int main()
{
    
    auto set_mid = [&](int a, int b, int c) {
        mid[a][b] = c;
        mid[b][a] = c;
    };
    set_mid(1, 3, 2);
    set_mid(1, 7, 4);
    set_mid(3, 9, 6);
    set_mid(7, 9, 8);
    set_mid(1, 9, 5);
    set_mid(3, 7, 5);
    set_mid(2, 8, 5);
    set_mid(4, 6, 5);

    string s;
    while(cin>>s) {
        int len = s.length();
        if(len>9) {cout<<"NO"<<endl; continue;}
        set<char> st;
        bool flag = true;
        for(int i=0;i<len;i++) {
            if(st.find(s[i])!=st.end()) {
                cout<<"NO"<<endl;
                flag = false;
                break;
            }
            st.insert(s[i]);
        } 
        set<int> v;
        int pre=0;
        if(!flag) continue;
        for(int i=0;i<len;i++) {
            if(pre!=0)
            {
                if(mid[pre][s[i]-'0']!=0 && v.find(mid[pre][s[i]-'0'])==v.end()) {
                    cout<<"NO"<<endl;
                    flag = false;
                    break;
                }
            }
            v.insert(s[i]-'0');
            pre=s[i]-'0';
        }
        if(!flag) continue;
        if(flag) {
            cout<<"YES"<<endl;
        }


    }
    return 0;
}