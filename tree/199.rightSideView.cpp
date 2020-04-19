// https://leetcode-cn.com/problems/binary-tree-right-side-view/
// 给定一棵树，站在树的右侧。按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
// python版（双端队列的使用）
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rightSideView(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        ret = []
        nodeQueue = deque()
        if not root:
            return ret
        nodeQueue.append(root)
        while len(nodeQueue):
            length = len(nodeQueue)
            #print('len=' + str(length) +'\n')
            while length:
                node = nodeQueue.popleft()
                if node.left:
                    nodeQueue.append(node.left)
                if node.right:
                    nodeQueue.append(node.right)
                length -= 1
                if length == 0:
                    ret.append(node.val)
        return ret


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
    vector<int> rightSideView(TreeNode* root) {
        deque<TreeNode*> nodeDeque;
        vector<int> res;
        if(root == NULL){
            return res;
        }
        nodeDeque.push_back(root);
        while(!nodeDeque.empty()){
            int len = nodeDeque.size();
            while(len){
                TreeNode* deleteNode = nodeDeque.front();
                nodeDeque.pop_front();
                if(deleteNode->left){
                    nodeDeque.push_back(deleteNode->left);
                }
                if(deleteNode->right){
                    nodeDeque.push_back(deleteNode->right);
                }
                len--;
                if(len == 0){
                    res.push_back(deleteNode->val);
                }
            }
        }
        return res;
    }
};
