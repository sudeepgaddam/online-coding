# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def hasPathSum(self, root, sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
        def helper(root, sum, currSum):
            if not root.left and not root.right:
                return sum == currSum + root.val
            else:
                return (root.left != None and helper(root.left, sum, currSum + root.val)) or                (root.right != None and helper(root.right, sum, currSum + root.val))
        if not root:
            return False
        return helper(root,sum,0)
