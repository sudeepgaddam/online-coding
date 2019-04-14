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
        
        def helper(root, path):
            if root.left:
                helper(root.left,path+str(root.val))
            if root.right:
                helper(root.right,path+str(root.val))
            if not root.left and not root.right:
                self.res = self.res + int(path+str(root.val))
        
        self.res = 0
        if not root:
            return self.res

        helper(root,'')
        return self.res
 
