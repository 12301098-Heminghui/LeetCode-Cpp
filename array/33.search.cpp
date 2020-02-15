//原题链接
// https://leetcode-cn.com/problems/search-in-rotated-sorted-array/submissions/
//思路：一个有序升序数组，从某个位置进行旋转后，数组某一部分依然保持有序的。
// 采用二分查找，利用数组左半边有序或者右半边有序的特征，来调节left和right指针

#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 0){
            return -1;
        }
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int middle = left + (right-left)/2;
            if(target < nums[middle]){
                //注意：nums[left]和nums[middle]的判断条件为小于等于
                //如果nums[left]<=nums[middle],说明数组左半边是有序的
                //这时如果target小于nums[left]，说明左半边肯定不存在等于target的值。
                if(nums[left] <= nums[middle] && target < nums[left]){
                    left = middle+1;
                }else{
                    right = middle-1;
                }
            }else if(target > nums[middle]){
                //注意：nums[left]和nums[middle]的判断条件为小于等于
                if(nums[middle] <= nums[right] && target > nums[right]){
                    right = middle-1;
                }else{
                    left = middle+1;
                }
            }else{
                return middle;
            }
        }
        return -1;
    }
};