/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:TreeNode* reConstruct(vector<int>& preorder, vector<int>& inorder, int pstart, int istart, int iend){
    if(istart > iend || iend > inorder.size()){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[pstart]);
    int start;
    for(int i = istart; i <= iend; i++){
        if(preorder[pstart] == inorder[i]) {
            start = i;
            break;
        }
    }
    if(start <= iend) {
        root->left = reConstruct(preorder, inorder, pstart+1, istart, start-1);
        root->right = reConstruct(preorder, inorder, pstart+start-istart+1, start+1, iend);
    }
    return root;
}
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return reConstruct(preorder, inorder, 0, 0, inorder.size()-1);
    }
};