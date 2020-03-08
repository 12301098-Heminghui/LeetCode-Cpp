// https://leetcode-cn.com/problems/first-missing-positive/
// 找到数组中缺失的最小正数(Hard)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 最小的正整数肯定是小于等于n+1的
        // 先判断1是否在数组里。
        int containOne = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] == 1){
                containOne++;
                break;
            }
        }
        // 1不在数组里直接返回1
        if(!containOne){
            return 1;
        }
        //1在数组里的前提下，如果nums只有一个元素，那返回值必然是2
        if(nums.size() == 1){
            return 2;
        }
        int n = nums.size();
        // 如果不是以上特殊情况，就对数据先进行预处理。（负数、大于n+1的数都设置为1）
        for(int i=0; i < n; i++){
            if(nums[i] <= 0 || nums[i] > n+1){
                nums[i] = 1;
            }
        }
        //接下来需要使用O(1)的空间复杂度来找到最小缺失正数
        for(int i = 0; i < n; i++){
            int a = fabs(nums[i]);
            //cout << "a=" << a <<",n=" << n << endl;

            if(a == n){
                nums[0] = a;                
            }

            if(a < n){
                nums[a] = -fabs(nums[a]);
            }
        }
        for(int i = 1; i < n; i++){
            //cout << "nums[i]" << nums[i] << endl;
            if(nums[i] > 0){
                return i;
            }
        }
        //如果1到n都存在，就返回n+1
        if(nums[0] == n){
            cout << "nums[0]=" << nums[0] << endl; 
            return n+1;
        }else{
            return n;
        }
    }
};