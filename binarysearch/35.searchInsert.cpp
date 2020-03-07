// https://leetcode-cn.com/problems/search-insert-position/
// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target){
                if(left == right){
                    return mid+1;
                }
                left++;
            }else if(nums[mid] > target){
                if(left == right){
                    return mid;
                }
                right--;
            }else{
                return mid;
            }
        }
        return left;
    }
};