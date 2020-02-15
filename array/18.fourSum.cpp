//原题链接：
// https://leetcode-cn.com/problems/4sum/submissions/

#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int> > res;
        if(len < 4){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++){
            for(int j = i+1; j < len; j++){
                int low = j+1;
                int high = len-1;
                while(low < high){
                    int s = nums[i]+nums[j]+nums[low]+nums[high];
                    if(s > target){
                        high--;
                    }else if(s < target){
                        low++;
                    }else{
                        vector<int> tmp_res {nums[i],nums[j],nums[low],nums[high]};
                        res.push_back(tmp_res);
                        while(low < high && nums[low] == nums[low+1]){
                            low++;
                        }
                        low++;
                        while(low < high && nums[high] == nums[high-1]){
                            high--;
                        }
                        high--;
                        
                    }
                }
                while(j < len-1 && nums[j] == nums[j+1]){
                    j++;
                }
            }
            while(i < len-1 && nums[i] == nums[i+1]){
                i++;
            }
        }
        return res;
    }

};