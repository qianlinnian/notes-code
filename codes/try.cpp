#include<iostream>
#include<string>
#include<set>
using namespace std; 

int next(int n)
{
    int res=0;
    while(n)
    {
        res+=(n%10)*(n%10);
        n/=10;
    }
    cout<<res<<'f';
    return res;
}

bool isHappy(int n) {
            string r=to_string(n);
            set<int> nums;
            nums.insert(n);
    
            while(n)
            {
                
                if(n==1)
                {
                    return true;
                }
                else 
                {
                    n=next(n); 
                    if(find(nums.begin(),nums.end(),n)==nums.end())
                    {
                        nums.insert(n);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return false;
        }
    int main()
    {
        int n;
        cin>>n;
        cout<<isHappy(n);
        return 0;
    }
