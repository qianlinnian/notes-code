/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        int len=path.length();
        string res="";
        string word="";
        vector<string> ss;
        for(int i=0;i<len;i++)
        {
            if(path[i]=='/')
            {
                for(int j=i+1;j<len;j++)
                {
                    if(path[j]!='/')                    
                        word+=path[j];                    
                    else
                    {
                        i=j-1;
                        break;
                    }
                }
                if(word=="..")  
                {
                    if (!ss.empty()) ss.pop_back(); 
                }
                else if(word==".")
                {}
                else if(word!="")
                {
                    ss.push_back(word);
                }
                word="";                            
            }
        }
        int size=ss.size();
        if(size)
        {
            for(string s:ss)
            {
                res.append("/");
                res.append(s);
            }
        }
        else
        {
            res="/";
        }

        return res;

    }
};
// @lc code=end

