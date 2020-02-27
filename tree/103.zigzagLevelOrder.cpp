// 原题链接：
// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 锯齿形层次遍历：只需要层次遍历的基础上，稍微改动就行。根据res的size判断是奇数层还是偶数层。
// 根据奇偶性判断是将值插入到vector的第0位，还是插入到vector的最后
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
    int level = res.size();
    for(int i = 0; i < nodeVec.size(); i++){
        if(nodeVec[i]->left){
            if(level%2 == 0){
                tmp_res.push_back(nodeVec[i]->left->val);
            }else{
                tmp_res.insert(tmp_res.begin(), nodeVec[i]->left->val);
            }
            currVec.push_back(nodeVec[i]->left);
        }
        if(nodeVec[i]->right){
            if(level%2 == 0){
                tmp_res.push_back(nodeVec[i]->right->val);
            }else{
                tmp_res.insert(tmp_res.begin(), nodeVec[i]->right->val);
            }
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
