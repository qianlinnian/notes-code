#include<iostream>
#include<string>
using namespace std; 


string countAndSay(int n) {
    if(n==1)
        return "1";
    else 
    {
        string last=countAndSay(n-1);
        string ans;
        int len=last.length(); 
        for(int i=0;i<len;)
        {
            int count=1;    

            while(++i<len && last[i]==last[i-1])
            {
                count++;
            }
            ans += '0' + count;
            ans += last[i-1];            
        }
        return ans;
    }
}

int main()
{
    cout<<countAndSay(1)<<endl; // Output: "1"
    cout<<countAndSay(2)<<endl; // Output: "11"
    cout<<countAndSay(3)<<endl; // Output: "21"
    cout<<countAndSay(4)<<endl; // Output: "1211"
    cout<<countAndSay(5)<<endl; // Output: "111221"
    return 0;
}