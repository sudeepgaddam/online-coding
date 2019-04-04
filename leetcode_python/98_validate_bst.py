# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isValidBST(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def helper(node, minVal, maxVal):
            if not node:
                return True
            if node.val <= minVal or node.val >= maxVal:
                return False
            return helper(node.left, minVal, node.val) and helper(node.right, node.val, maxVal)
        return helper(root,-sys.maxint-1, sys.maxint)

            
        
