// 原题链接：
// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// 树的中序遍历：递归和迭代两种方式来实现

//递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<vector>;
using namespace std;

 void recursion(TreeNode* node, vector<int>& res){
     if(node == NULL){
         return;
     }else{
        recursion(node->left, res);
        res.push_back(node->val);
        recursion(node->right, res);
     }
 }
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        recursion(root, res);
        return res;
    }
};


//迭代：整体思想是想遍历左孩子，然后访问当前节点，再遍历右孩子

//方法一
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> tree_stack;
        tree_stack.push(root);
        while(!tree_stack.empty()){
            TreeNode* curr = tree_stack.top();//获取栈顶元素
            if(curr->left == NULL){
                res.push_back(curr->val);
                tree_stack.pop();
                if(curr->right != NULL){
                    tree_stack.push(curr->right);
                }
            }else{
                tree_stack.push(curr->left);
                curr->left = NULL; //此处改变了树的结构
            }
        }
        return res;
    }
};

//方法二：定义一个判断节点是否已经入栈
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> tree_stack;
        map<TreeNode*, int> node_map;
        tree_stack.push(root);
        node_map[root] = true;
        while(!tree_stack.empty()){
            TreeNode* curr = tree_stack.top();//获取栈顶元素
            if(curr->left == NULL || node_map[curr->left]){
                res.push_back(curr->val);
                tree_stack.pop();
                if(curr->right != NULL){
                    tree_stack.push(curr->right);
                }
            }else{
                tree_stack.push(curr->left);
                node_map[curr->left] = true;
            }
        }
        return res;
    }
};

//方法三：


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> tree_stack;
        TreeNode* pCurrent = root;
        //先遍历左子树，然后访问栈顶元素，然后遍历右子树
        while(!tree_stack.empty() || pCurrent){
            if(pCurrent){
                tree_stack.push(pCurrent);
                pCurrent = pCurrent->left;
            }else{
                TreeNode* top = tree_stack.top();
                res.push_back(top->val);
                pCurrent = top->right;
                tree_stack.pop(); 
            }
        }
        return res;
    }
};