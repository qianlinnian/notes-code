#include<iostream>
#include<vector>
#include<string>
 
using namespace std;
int strStr(string haystack, string needle) {
//kmp
    int len1=haystack.length();
    int len2=needle.length();
    vector<int> next(len2,0);
    int j=0;
    for(int i=0;i<len2;i++)
    {
        while (j > 0 && needle[i] != needle[j]) {
            j = next[j - 1];
            
            if (needle[i] == needle[j]) {
               j++;
            }
            next[i] = j;
        }
    
        j=0;
        for (int i = 0; i <len1; i++) {  
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            
            if (haystack[i] == needle[j]) {
                j++;
            }
            
            if (j == len2) {
                return i - len2 + 1;
            }
        }
    }
        return -1;
}

int main()
{
    int r=strStr("leetcode","leeto");
    cout<<r;
    return  0;
}