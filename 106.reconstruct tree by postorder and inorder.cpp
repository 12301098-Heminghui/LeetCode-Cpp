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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return reConstruct(inorder, 0, inorder.size()-1, postorder, inorder.size()-1);
    }
    TreeNode* reConstruct(vector<int>& inorder, int istart, int iend, vector<int>& postorder, int pstart) {
        if(istart > iend) {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[pstart]);
        int start = 0;
        for (int i = istart; i <= iend; i++) {
            if (postorder[pstart] == inorder[i]) {
                start = i;
                break;
            }
        }
        root->right = reConstruct(inorder, start+1, iend, postorder, pstart-1);
        root->left = reConstruct(inorder, istart, start-1, postorder, pstart-1-(iend-start));
        return root;
    }
};