/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

// B是A的子结构， 即 A中有出现和B相同的结构和节点值。
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL || A == NULL){
            return false;
        }
        bool start = false;
        return isSame(A,B,start);
    }
bool isSame(TreeNode* A, TreeNode* B, bool & start){
    if(B == NULL){
        return true;
    }
    if(A == NULL){
        return false;
    }
    if(A->val == B->val){
        start = true;
        return isSame(A->left, B->left, start) && isSame(A->right, B->right, start);
    }else if(start){
        return false;
    }else{
        return isSame(A->left, B, start) || isSame(A->right, B, start);
    }
    return false;
}
};

// python版

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSubStructure(self, A, B):
        """
        :type A: TreeNode
        :type B: TreeNode
        :rtype: bool
        """
        def isSame(A, B, start):
            if B == None:
                return True
            if A == None:
                return False
            
            if A.val == B.val:
                start = True
                return isSame(A.left, B.left, start) and isSame(A.right, B.right, start)
            elif start:
                return False
            else:
                return isSame(A.left, B, start) or isSame(A.right, B, start)
            return False
        start = False
        if B == None or A == None:
            return False
        return isSame(A,B,start)