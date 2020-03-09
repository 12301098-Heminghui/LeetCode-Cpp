// https://leetcode-cn.com/problems/permutations/
// 给定一个没有重复数字的序列，返回其所有可能的全排列。

// 典型回溯法

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        helper(nums, path, res);
        return res;
    }
void helper(vector<int>& nums, vector<int>& path, vector<vector<int>>& res){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0; i < nums.size(); i++){
        if(find(path.begin(), path.end(), nums[i]) != path.end()){
            continue;
        }else{
            path.push_back(nums[i]);
            helper(nums, path, res);
            path.pop_back();
        }
    }
}
};
