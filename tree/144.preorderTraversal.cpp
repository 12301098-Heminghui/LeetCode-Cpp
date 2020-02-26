// 原题链接：
// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
// 二叉树前序遍历

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//递归实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        traversal(root, res);
        return res;
    }
void traversal(TreeNode* node, vector<int>& res){
    res.push_back(node->val);
    if(node->left){
        traversal(node->left, res);
    }
    if(node->right){
        traversal(node->right, res);
    }  
}
};

// 迭代法实现
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> treeStack;
        TreeNode* p = root;
        while(!treeStack.empty() || p){
            if(p){
                res.push_back(p->val);
                if(p->right){
                    treeStack.push(p->right);
                }
                p = p->left;
            }else{
                p = treeStack.top();
                treeStack.pop();
            }
        }
        return res;
    }
};