/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {
        vector< vector<int> > res;
        //如果nums的大小小于3
        if(nums.size() < 3){
            return res;
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //i 表示指向vector的一个左指针
        for(int i = 0; i < n-2; i++){
            if(nums[i] > 0){
                return res;
            }
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i+1;
            int right = n-1;
            while(left < right){
                //如果最右边元素都小于0，则不可能存在三数之和等于0，直接break
                if(nums[right] < 0){
                    break;
                }
                int s = nums[i] + nums[left] + nums[right];
                if(s > 0){
                    right--;
                }else if(s < 0){
                    left++;
                }else{
                    //找到三元组
                    vector<int> tmp_res {nums[i], nums[left], nums[right]};
                    res.push_back(tmp_res);
                    // while (left < right && nums[left] == nums[++left]);
                    // while (left < right && nums[right] == nums[--right]);
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    left++;
                    while(right > left && nums[right] == nums[right-1]){
                        right--;
                    }
                    right--;
                }
            }
        }
        return res; 
    }
};
// @lc code=end

