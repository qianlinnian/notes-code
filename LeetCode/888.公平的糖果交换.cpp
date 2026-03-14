/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */

// @lc code=start
class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int suma=0,sumb=0,sum=0;
        int n=aliceSizes.size(),m=bobSizes.size();
        sort(aliceSizes.begin(),aliceSizes.end());
        sort(bobSizes.begin(),bobSizes.end());
        for(int c:aliceSizes)
        {
            suma+=c;
        }
        for(int c:bobSizes)
        {
            sumb+=c;
        }
        sum=suma+sumb;
        int half=sum/2;
        for(int c:aliceSizes)
        {
            int gap= half-(suma-c);
            if(gap<=0)
                continue;
            for(int i=0;i<m;i++)
            {
                if(bobSizes[i]==gap)
                {
                    vector<int> answer;
                    answer.push_back(c);
                    answer.push_back(gap);
                    return answer;
                }
                else if(bobSizes[i]<gap)
                {
                    continue;
                }
            }
        }
        vector<int> answer;
        return answer;
    }
};
// @lc code=end

