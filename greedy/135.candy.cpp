// https://leetcode-cn.com/problems/candy/

// 分发糖果。
// 从左到右 贪心原则 使得学生的糖果满足左规则
// 从右到左 贪心原则 使得学生的糖果满足右规则

class Solution {
public:
    int candy(vector<int>& ratings) {
        int num = ratings.size();
        vector<int> left2right;
        vector<int> right2left;
        left2right.assign(num,1);
        right2left.assign(num,1);
        for(int i = 1; i < num; i++){
            // 大于左边
            if(ratings[i] > ratings[i-1]){
                left2right[i] = max(left2right[i], left2right[i-1]+1);
            }
        }
        for(int i = num-2; i >= 0; i--){
            // 大于右边
            if(ratings[i] > ratings[i+1]){
                right2left[i] = max(right2left[i], right2left[i+1] + 1);
            }
        }
        int res = 0;
        for(int i=0; i < num; i++){
            res += max(left2right[i], right2left[i]);
        }
        return res;
    }
};
