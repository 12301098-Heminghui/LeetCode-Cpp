// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。

class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int index = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i]%2 == 1){
                swap(nums[index], nums[i]);
                index++;
            }
        }
        return nums;
    }
};