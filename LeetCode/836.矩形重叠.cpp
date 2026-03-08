/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */

// @lc code=start
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        double x1=(rec1[0]+rec1[2])/2.0;
        double y1=(rec1[1]+rec1[3])/2.0;
        double x2=(rec2[0]+rec2[2])/2.0;
        double y2=(rec2[1]+rec2[3])/2.0;
        double w1=abs(rec1[2]-rec1[0])/2.0;
        double h1=abs(rec1[3]-rec1[1])/2.0;
        double w2=abs(rec2[2]-rec2[0])/2.0;
        double h2=abs(rec2[3]-rec2[1])/2.0;
        return abs(x1-x2)<(w1+w2) && abs(y1-y2)<(h1+h2);
    }
};
// @lc code=end

