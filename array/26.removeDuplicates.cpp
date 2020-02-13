//原题链接:
//https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/submissions/
//思路：题目要求只能在原数组中进行修改，并且只能使用额外的o(1)的空间。
//定义一个可插入的指针index标识。当第i个元素和index位置的元素值相等时，i继续往后遍历；
// 当两个值不相等时，需要判断这两个位置是否为邻居，不为邻居的情况下，index+1的位置可赋值为i位置的元素值
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0){
            return len;
        }
        int index = 0;
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[index]){
                if(index+1 != i){
                    nums[index+1] = nums[i];
                }
                index++;
            }else{
                continue;
            }
        }
        return index+1;
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if (len <= 0){
            return len;
        }
        int index = 0;
        int res = 1;
        for(int i = 1; i < len; i++){
            if(nums[i] != nums[index]){
                nums[index+1] = nums[i];
                index++;
            }else{
                continue;
            }
        }
        return index+1;
    }
};