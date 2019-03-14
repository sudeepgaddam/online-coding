# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        mp = {}
        mp[None] = 0
        self.ans = 1
        def maxDepth(root):
            if not root:
                return 0
            l = maxDepth(root.left)
            r = maxDepth(root.right)
            self.ans = max(self.ans, l+r+1)
            return max(l,r) + 1
        maxDepth(root)
        return self.ans-1
