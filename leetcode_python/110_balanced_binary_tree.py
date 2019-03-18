# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        mp = {}
        mp[None] = 0
        def calcHeights(root):
            if root in mp:
                return mp[root]
            if not root.left and not root.right:
                mp[root] = 1
                return mp[root]
            mp[root] = max(calcHeights(root.left), calcHeights(root.right)) + 1
            return mp[root]
        calcHeights(root)
        for k in mp.keys():
            if k:
                if abs(mp[k.left]-mp[k.right])>1:
                    return False
        return True
