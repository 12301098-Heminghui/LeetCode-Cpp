
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。
// 数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
// 存在重复的数字，返回任意一个就行。不存在重复的数字，返回-1即可

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int,int> number_map;
        for(int i=0; i < nums.size(); i++){
            if(number_map.find(nums[i]) != number_map.end()){
                return nums[i];
            }else{
                number_map[nums[i]] = 1;
            }
        }
        return -1;
    }
};