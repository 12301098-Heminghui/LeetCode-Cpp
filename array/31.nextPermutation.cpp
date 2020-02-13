//原题链接:
//https://leetcode-cn.com/problems/next-permutation/submissions/
//思路：
// 首先需要从右往左找到一对两个连续的数字 a[i]和a[i-1],a[i-1] < a[i] 此时找到a[i-1]称为待交换的较小数
// 此时a[i]到数组末尾为一个降序排列
// 由于题目要求找下一个更大的排序，因此再次从右往左寻找第一个大于a[i-1]的数a[j]
// 交换a[i-1]和a[j],然后将i到数组末尾的有序序列进行反转即可

#include<vector>
using namespace std;
#include<iostream>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int len = nums.size();
        //从右往左找到小数
        int i = len-1;
        int j = len-1;
        while(i>0 && nums[i-1] >= nums[i]){
            i--;
            cout << "for loop i is : " << i << endl;
        }
        i--;
        cout << "min num: " << i << endl;
        if(i >= 0){
            //从右往前找到第一个大于小数的数（大数）
            while(j > i && nums[j] <= nums[i]){
                j--;
                cout << "for loop j is : " << j << endl;
            }

            swap(nums, i, j);
        }
        reverse(nums, i+1);
    }
    void reverse(vector<int>& nums, int start){
        //有序数组的反转
        int i = start;
        int j = nums.size()-1;
        while(i < j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    void swap(vector<int>& nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
