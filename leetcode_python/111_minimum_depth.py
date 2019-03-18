# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        q= collections.deque()
        if not root:
            return 0
        q.append((root,1))
        while q:
            nd,level = q.popleft()
            if not nd.left and not nd.right:
                return level
            if nd.left:
                q.append((nd.left,level+1))
            if nd.right:
                q.append((nd.right,level+1))
