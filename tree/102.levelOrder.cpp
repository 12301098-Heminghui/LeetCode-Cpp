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

// 层次遍历，迭代方法

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        //先进先出，用c++里的队列来实现
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        while(!treeQueue.empty()){
            int length = treeQueue.size();
            vector<int> tmp;
            for(int i = 0; i < length; i++){
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                tmp.push_back(node->val);
                if(node->left){
                    treeQueue.push(node->left);
                }
                if(node->right){
                    treeQueue.push(node->right);
                }
            }
            res.push_back(tmp);
        }
        return res;
    }
};