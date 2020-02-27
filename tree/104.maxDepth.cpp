// 原题链接：
// https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

// 求树的最大深度，递归做法
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
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return calDepth(root, 0);
    }
int calDepth(TreeNode* node, int depth){
    if(node == NULL){
        return depth;
    }
    return max(calDepth(node->left, depth), calDepth(node->right, depth)) + 1;
}
};
