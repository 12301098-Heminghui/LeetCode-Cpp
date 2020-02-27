// 原题链接：
// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/

// 递归法
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        traversal(root, res);
        return res;
    }
void traversal(TreeNode* node, vector<int>& res){
    if(node->left){
        traversal(node->left, res);
    }
    if(node->right){
        traversal(node->right, res);
    }
    res.push_back(node->val);
}
};

// 迭代法
// 思想：考虑先序遍历和后续遍历的关系
// 先序遍历：根->左->右 （先访问节点，然后将右孩子压入栈，继续遍历左孩子直到左孩子为空）
// 后续遍历：左->右->根。
// 1.对先序遍历改动1：如果按照先序遍历的逻辑，但是在访问节点时，将其插入到vector第0位，则右->左->根
// 2.对先序遍历改动2：如果先遍历右孩子，再遍历左孩子，则变成 根->右->左
// 结合1和2两点，将当前节点加入vector第0位，再遍历右孩子，再遍历左孩子。则有 左->右->根
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> treeStack;
        TreeNode* p = root;
        while(p || !treeStack.empty()){
            if(p){
                res.insert(res.begin(), p->val);
                if(p->left){
                    treeStack.push(p->left);
                }
                p = p->right;
            }else{
                p = treeStack.top();
                treeStack.pop();
            }  
        }
        return res;
    }
};
