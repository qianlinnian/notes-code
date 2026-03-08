/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution {
public:
    int binaryGap(int n) {
        vector<int> pos;
        int index=0;
        while(n>0){
            if((n&1)==1){
                pos.push_back(index);
            }
            n=n>>1;
            index++;
        }
        int size=pos.size();
        if(size<2){
            return 0;
        }
        else{
            int result=0;
            for(int i=1;i<size;i++){
                result=max(result,pos[i]-pos[i-1]);
            }
            return result;
        }
    }
};
// @lc code=end

