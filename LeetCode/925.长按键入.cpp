/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int ln=name.length(),lt=typed.length();
        char c=name[0];
        int len1=1,len2=0;
        int pos=0;
        for(int i=1;i<ln;i++)
        {
            if(name[i]!=c)
            {
                for(int i=pos;i<lt;i++)
                {
                    if(typed[i]==c)
                        len2++;                    
                    else
                        break;
                }
                if(len2<len1)
                {
                    return false;
                }
                len1=1,len2=0;
                c=name[i];
            }
            else{
                len1++;
            }
        }
        return true;

    }
};
// @lc code=end

