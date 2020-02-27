// 原题链接：
// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/

// 层次遍历，递归方法

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        res.push_back({root->val});
        vector<TreeNode*> lastLevel = {root};
        travesal(lastLevel, res);
        return res;
    }
void travesal(vector<TreeNode*>& nodeVec, vector<vector<int>>& res){
    vector<TreeNode*> currVec;
    vector<int> tmp_res;
    cout << "size: "<< nodeVec.size()<<endl;
    for(int i = 0; i < nodeVec.size(); i++){
        if(nodeVec[i]->left){
            tmp_res.push_back(nodeVec[i]->left->val);
            currVec.push_back(nodeVec[i]->left);
        }
        if(nodeVec[i]->right){
            tmp_res.push_back(nodeVec[i]->right->val);
            currVec.push_back(nodeVec[i]->right);
        }
    }
    if(tmp_res.size() <= 0){
        return;
    }
    res.push_back(tmp_res);
    travesal(currVec, res);
}
};