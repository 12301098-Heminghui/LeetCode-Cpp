//原题链接
//https://leetcode-cn.com/problems/3sum-closest/submissions/
//解题思路: 对排序后的数组，从第0位开始遍历，利用额外的left、right指针，得到三个数之和。
// 判断三个数之和与target的差值的绝对值 与 当前 最小差值 比较，更新最小差值以及三数之和


#include<vector>
using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len < 3){
            return -target;
        }
        sort(nums.begin(), nums.end());
        int min_diff = INT_MAX;
        int close_sum = 0;
        for(int i = 0; i < len-2; i++){
            int left = i+1;
            int right = len-1;
            while(left < right){
                int s = nums[i] + nums[left] + nums[right];
                if (abs(min_diff) > abs(s-target)){
                    close_sum = s;
                    min_diff = abs(s-target);
                }
                if(s > target){
                    right--;
                }else if(s < target){
                    left++;
                }else{
                    return target;
                }
            }
        }
        return close_sum;
    }
};