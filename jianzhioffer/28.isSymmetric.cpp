/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root){
            return recursion(root->left, root->right);
        }else{
            return true;
        }
    }
bool recursion(TreeNode* left, TreeNode* right){
    if(!left && !right){
        return true;
    }
    if(left && right && left->val == right->val){
        return recursion(left->left, right->right) && recursion(left->right, right->left);
    }else{
        return false;
    }
    return true;
}
};

// 迭代

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
    bool isSymmetric(TreeNode* root) {
        if(root){
            //迭代的方法
            queue<TreeNode*> q;
            q.push(root->left);
            q.push(root->right);
            while(!q.empty()){
                TreeNode* A = q.front();q.pop();
                TreeNode* B = q.front();q.pop();
                if(A==NULL && B==NULL){
                    continue;
                }
                if(A && B && A->val == B->val){
                    q.push(A->left);
                    q.push(B->right);
                    q.push(A->right);
                    q.push(B->left);
                }else{
                    return false;
                }
            }
            return true;

        }else{
            return true;
        }
    }
};