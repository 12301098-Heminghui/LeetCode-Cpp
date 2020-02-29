// 原题链接：
// https://leetcode-cn.com/problems/validate-binary-search-tree/

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
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return isValid(root, LONG_MIN, LONG_MAX);
    }
bool isValid(TreeNode* node, long low, long high){
    if(!node){
        return true;
    }
    //先判断当前节点是否在上下界之间，然后遍历节点的左结点（更新上下界），遍历节点的右节点（更新上下界）
    if(node->val <= low){
        return false;
    }
    if(node->val >= high){
        return false;
    }
    if(!isValid(node->left, low, node->val)){
        return false;
    }
    if(!isValid(node->right,node->val, high)){
        return false;
    }
      return true;
    }
};


// TODO : 迭代法