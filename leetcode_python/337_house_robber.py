# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        mp = {}
        def helper(root):
            if root in mp:
                return mp[root]
            leftGrand = 0
            rightGrand = 0
            if root.left:
                leftGrand = helper(root.left.left) + helper(root.left.right)
            if root.right:
                rightGrand = helper(root.right.left) + helper(root.right.right)
            mp[root] = max((root.val + rightGrand + leftGrand), helper(root.left) + helper(root.right))
            return mp[root]
        mp[None] = 0
        return helper(root)
