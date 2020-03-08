// https://leetcode-cn.com/problems/combination-sum-ii/
// 与combination-sum不同的是，数组中的元素不可以重复使用，而且数组中可能存在重复元素。
// 返回结果要求一致（都是要求返回的组合不能重复）

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, combi, target, 0);
        return res;
    }
void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combi, int target, int start){
    if(target == 0){
        res.push_back(combi);
        return;
    }
    if(target < 0){
        return;
    }
    for(int i = start; i < candidates.size(); i++){
        if(candidates[i] > target){
            break;
        }
        combi.push_back(candidates[i]);
        helper(candidates, res, combi, target-candidates[i], i+1);
        combi.pop_back();
        // 遇到相同的元素，则跳过，不需要进行遍历
        while(i < candidates.size()-1 && candidates[i+1] == candidates[i]){
            i++;
        }
    }
}
};