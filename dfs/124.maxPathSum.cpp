// https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

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
int maxPathSumHelper(TreeNode* node, int &val){
    if(node == NULL){
        return 0;
    }
    int left = maxPathSumHelper(node->left,val);
    int right = maxPathSumHelper(node->right,val);
    //以当前节点为新路径的第一个节点
    int sum1 = node->val + max(0, left) + max(0, right);
    // 连接当前节点的父亲
    int sum2 = node->val + max(0, max(left, right));
    val = max(val, max(sum1, sum2));
    return sum2;
}
public:
    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        maxPathSumHelper(root, val);
        return val;
    }
};