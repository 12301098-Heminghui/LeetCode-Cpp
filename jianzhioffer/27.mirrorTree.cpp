









// python 版
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def mirrorTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def recursion(node):
            if not node:
                return
            left = node.left
            right = node.right
            node.left = recursion(right)
            node.right = recursion(left)
            return node
        return recursion(root)
