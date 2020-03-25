// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。


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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inorderMap;
        int size = inorder.size();
        for(int i=0; i < size; i++){
            inorderMap[inorder[i]] = i;
        }
        return build(preorder, inorderMap, 0, 0, size-1);
    }
    TreeNode* build(vector<int>& preorder, map<int,int>& indexMap, int prebegin, int inbegin, int inend){
        /**
        此处，indexMap使用值传递，则一直报超时；换成引用传递就能ac。
        */
        if(inbegin > inend){
            return NULL;
        }
        int index = indexMap[preorder[prebegin]]; //preorder节点在inorder里的index
        int leftLen = index-inbegin;
        TreeNode* node = new TreeNode(preorder[prebegin]);
        node->left = build(preorder, indexMap, prebegin+1, inbegin, index-1);
        node->right = build(preorder, indexMap, prebegin+leftLen+1, index+1, inend);
        return node;
    }
};
