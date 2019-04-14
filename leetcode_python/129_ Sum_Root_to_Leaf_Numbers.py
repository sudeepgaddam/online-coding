# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        
        def helper(root, sum):
            if root.left:
                helper(root.left,sum*10+root.val)
            if root.right:
                helper(root.right,sum*10+root.val)
            if not root.left and not root.right:
                self.res = self.res + (sum*10+root.val)
        
        self.res = 0
        if not root:
            return self.res

        helper(root,0)
        return self.res
 
