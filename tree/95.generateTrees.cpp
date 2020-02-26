// 原题链接：
// https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
// 题目要求：给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树
// 思路：以i作为根节点，求出左子树集合，右子树集合。左右子树集合进行两两组合。
// 构造子树时，同样是把某个数当做根节点，左右子树集合两两组合。这是一个递归的过程

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
    vector<TreeNode*> generateTrees(int n) {
        if(n <= 0){
            return {};
        }
        return generateTree(1,n);
    }
 vector<TreeNode*> generateTree(int start, int end){

     vector<TreeNode*> allTrees;
     if(start > end){
         allTrees.push_back(NULL);
     }
     for(int i = start; i <= end; i++){
         vector<TreeNode*> leftTrees = generateTree(start, i-1);
         vector<TreeNode*> rightTrees = generateTree(i+1, end);
         for(auto ltree: leftTrees){
             for(auto rtree: rightTrees){
                 TreeNode* root = new TreeNode(i);
                 root->left = ltree;
                 root->right = rtree;
                 allTrees.push_back(root);
             }
         }
     }
     return allTrees;
 }   
};