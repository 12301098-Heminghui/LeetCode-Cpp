// https://leetcode-cn.com/problems/trapping-rain-water/
// 接雨水

class Solution {
public:
    int trap(vector<int>& height) {
        // 当前位置的储水量，取决于它的左右柱子中较小值的柱子。矮一些的柱子减去当前柱子的高度，则是这个柱子的储水量
        int res = 0;
        for(int i = 1; i < height.size(); i++){
            int left = 0;
            int right = 0;
            //左边搜索最高的柱子
            for(int j=i; j>= 0; j--){
                left = max(left, height[j]);
            }
            //左边搜索最高的柱子
            for(int j=i; j < height.size(); j++){
                right = max(right, height[j]);
            }
            res += min(left, right) - height[i];
        }
        return res;
    }
};
