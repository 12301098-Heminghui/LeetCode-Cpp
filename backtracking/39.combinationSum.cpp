// https://leetcode-cn.com/problems/combination-sum/
// 给定一个无重复元素的数组和一个target值，找出所有组合使得组合元素和等于target
// 注意：解集不能包含重复组合

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        set<vector<int>> resSet;
        vector<int> combi;
        helper(candidates, resSet, combi, target);
        // 这里使用一个set来维护，使得解集不包含重复组合
        res.insert(res.begin(), resSet.begin(), resSet.end());
        return res;
    }
void helper(vector<int>& candidates, set<vector<int>>& res, vector<int>& combi, int target){
    int sum = 0;
    for(auto val: combi){
        sum += val;
    }
    if(target == sum){
        //此处不能直接对combi进行sort，因为递归里对combi有pop_back操作
        vector<int> tmp = combi; 
        sort(tmp.begin(),tmp.end());
        res.insert(tmp);
        return;
    }
    if(sum > target){
        return;
    }
    for(int i = 0; i < candidates.size(); i++){
        combi.push_back(candidates[i]);
        helper(candidates, res, combi, target);
        combi.pop_back();
    }
}
};

// 改进版：先对candidates进行排序，后面深度优先遍历时，start位置从当前位置开始

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> combi;
        sort(candidates.begin(), candidates.end());
        helper(candidates, res, combi, target, 0);
        return res;
    }
void helper(vector<int>& candidates, vector<vector<int>>& res, vector<int>& combi, int redu, int start){
    if(redu == 0){
        res.push_back(combi);
        return;
    }
    if(redu < 0){
        return;
    }
    for(int i = start; i < candidates.size(); i++){
        // 此处加上一个break判断，如果当前元素都大于差值，说明后续元素也不用遍历。
        if(redu < candidates[i]){
            break;
        }
        combi.push_back(candidates[i]);
        helper(candidates, res, combi, redu-candidates[i], i);
        combi.pop_back();
    }
}
};