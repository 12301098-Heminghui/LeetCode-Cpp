using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
    
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> intMap;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int value = target - nums[i];
            if (intMap.find(nums[i]) != intMap.end()){
                result.push_back(intMap[nums[i]]);
                result.push_back(i);
                return result;
            }else {
                intMap[value] = i;
                
            }
        }
        return {};
    }
};

#include <unordered_map>
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> twoSumMap;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if (twoSumMap.find(nums[i]) != twoSumMap.end()) {
                result.push_back(i);
                result.push_back(twoSumMap[nums[i]]);
                return result; 
            }else{
                twoSumMap[target-nums[i]] = i;
            }
        }
        return result;
        
    }
};