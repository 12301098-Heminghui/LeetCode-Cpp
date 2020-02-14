//原题链接：
//https://leetcode-cn.com/problems/remove-element/submissions/
//思路：定义一个标识当前可插入值的位置指针index
// 遍历数组，遇到第一个等于target的位置，赋值给index。
// 如果数组元素不等于target，则进一步判断是否有可插入的位置(index不等于-1，表示index位置可插入)

#include<vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() <= 0){
            return 0;
        }
        int index = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                if(index != -1){
                    nums[index] = nums[i];
                    index++;
                }  
            }else{
                if(index == -1){
                    index = i;
                }
            }
        }
        //此处如果index=-1,说明数组中没有值为val的元素
        if(index == -1){
            return nums.size();
        }
        return index;
    }
};