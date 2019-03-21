# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def longestUnivaluePath(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def helper(node):
            if not node:
                return 0
            currLeft, currRight= 0,0
            
            leftVal = helper(node.left)
            rightVal = helper(node.right)

            if node.left and node.val == node.left.val:
                currLeft += leftVal + 1

            if node.right and node.val == node.right.val:
                currRight += rightVal + 1

            self.maxResult  = max(self.maxResult, currLeft + currRight)
            return max(currLeft,currRight)
        
        self.maxResult = 0
        helper(root)
        return self.maxResult

            
