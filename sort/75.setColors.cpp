//原题链接：
// https://leetcode-cn.com/problems/sort-colors/
// 思路：由于数组中只有0，1，2三种值，需要使用两个index指针，将数组分成三部分、
// (一个指针指示0的右边界，另一个指针指示2的左边界)
// 问题变成了找到这两个指针的合适位置
//这两个指针先初始化为数组的首端和末端，定义一个指向当前要位置的指针，根据curr指针对应的值来移动left、right指针。
// 当curr对应值为0时，将curr对应值与left对应值交换，curr右移，left也右移
// 当curr对应值为2时，将curr对应值与right对应值交换，right左移(此时curr不能右移，因为此时不能保证curr的值为0)
// 当curr对应值为1时，curr右移

#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int curr = 0;
        int right = nums.size()-1;
        while(curr <= right){
            if(nums[curr] == 0){
                swap(nums[curr], nums[left]);
                curr++;
                left++;
            }else if(nums[curr] == 2){
                swap(nums[curr], nums[right]);
                right--;
            }else{
                curr++;
            }
        }
    }
};