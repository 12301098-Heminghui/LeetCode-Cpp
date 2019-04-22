#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 0){
            return 0;
        }
        int gap = 0;
        for(int i = 1; i < len; i++){
            if(nums[i] == nums[i-1]){
                gap++;
            }else{
                nums[i-gap] = nums[i];
            }
        }
        for(int i = 0; i < gap; i++){
            nums.pop_back();
        }
        return len-gap;
    }
};