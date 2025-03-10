#include<iostream>
#include<string>
#include<set>
using namespace std; 
bool isAnagram(string s, string t) {
    int ss[27]={0},tt[27]={0};

    int len=s.length();
    int len1=t.length();
    if(len!=len1)
    {
        return false;
    }
    
    for(int i=0;i<len;i++)
    {
        //cout<<s[i]<<' ';
        ss[s[i]-'a']++;
        tt[t[i]-'a']++;
    } 
    for(int i=0;i<=26;i++)
    {
        cout<<ss[i]<<' ';
        if(ss[i]!=tt[i])
        {
            return false;
        }
    }
    return true;
}
    int main()
    {
        string s="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
        string t="bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbba";
        cout<<isAnagram(s,t);
        return 0;
    }
