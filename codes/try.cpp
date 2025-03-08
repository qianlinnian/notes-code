#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string s) {
    int len=s.length();
    int con=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
        {
            s[i]+='a'-'A';
            continue;
        }
        if(!((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9')))
        {
            ++con;
        }
        else
        {
            s[i-con]=s[i];
        }
    }
    int lenc=len-con;

    for(int i=0;i<=lenc/2;i++)
    {
        if(s[i]!=s[lenc-i-1])
            return false;
    }
    return true;

}

int main()
{
    string s="A man, a plan, a canal: Panama";
    cout<<isPalindrome(s);
    return 0;
}