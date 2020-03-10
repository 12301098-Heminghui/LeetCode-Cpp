// https://leetcode-cn.com/problems/permutations-ii
// 给定一个可能包含重复元素的数组，输出该数组对应的所有不重复的全排列

// 相对于LeetCode46,此题不同之处在于数组中可能有重复元素。
// 因此在回溯时，不能简单的判断元素是否已经在path中来决定元素是否加入path
// 还有一处需要注意：由于存在重复元素，又不能返回重复的全排列，所以在遇到同样值的元素时，不需要进行多次回溯。

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        cout << "nums.size=" << nums.size() << endl;
        map<int, bool> flag;
        for(int i=0; i < nums.size(); i++){
            flag[i] = false;
        }
        helper(nums, path, res, flag);
        return res;
    }
void helper(vector<int>& nums, vector<int>& path, vector<vector<int>>& res, map<int,bool> flag){
    if(path.size() == nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0; i < nums.size(); i++){
            if(flag[i]){
                continue;
            }else{
                flag[i] = true;
                path.push_back(nums[i]);
                helper(nums, path, res, flag);
                path.pop_back();
                flag[i] = false;
                // 此处是跳过重复元素进行回溯操作
                while(i < nums.size()-1 && nums[i+1] == nums[i]){
                    i++;
                }
            }
    }
}
};
