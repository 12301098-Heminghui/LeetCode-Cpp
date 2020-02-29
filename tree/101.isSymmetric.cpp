// 原题链接：
// https://leetcode-cn.com/problems/symmetric-tree/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//递归法
// 思路：

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return traversal(root->left, root->right);
    }
bool traversal(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL){
        return true;
    }
    bool leftFlag = false;
    bool rightFlag = false;
    if(left != NULL && right != NULL && left->val == right->val){
        leftFlag = traversal(left->left, right->right);
        rightFlag = traversal(left->right, right->left);
    }else{
        return false;
    }
    if(leftFlag && rightFlag){
        return true;
    }else{
        return false;
    }
}
};

// 迭代法
// 初始化：将根节点两次加入队列。
// while循环里：比较队列里两个连续的节点是否值相同，相同的话，则将两个节点的左右孩子按照相反的顺序加入队列

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        treeQueue.push(root);
        while(!treeQueue.empty()){
        TreeNode* left = treeQueue.front();
        treeQueue.pop();
        TreeNode* right = treeQueue.front();
        treeQueue.pop();
        if(left == NULL && right == NULL){
            continue;
        }
        if(left == NULL || right == NULL){
            return false;
        }
        //left和right都不为null，则比较节点的值
        if(left->val != right->val){
            return false;
        }
        //此处注意进队列的顺序
        treeQueue.push(left->left);
        treeQueue.push(right->right);
        treeQueue.push(left->right);
        treeQueue.push(right->left);
        }
        return true;
    }
};