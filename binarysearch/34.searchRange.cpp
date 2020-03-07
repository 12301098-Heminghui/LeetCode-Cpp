// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// 给定一个有序数据和一个target，求数组中等于这个target的左右边界

// 二分查找的应用。在找到等于target的元素后，继续向左、向右搜索等于target的index

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> res;
        bool isFind = false;
        int low = -1;
        int high = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else if(nums[mid] < target){
                left = mid+1;
            }else{
                isFind = true;
                low = mid;
                high = mid;
                while(high < nums.size()-1 && nums[high+1] == target){
                    high++;
                }
                while(low > 0 && nums[low-1] == target){
                    low--;
                }
                return {low,high};
            }
        }
        return {-1,-1};
    }
};