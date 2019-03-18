# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Runtime: 24 ms, faster than 100.00% of Python online submissions for Binary Tree Level Order Traversal II.
# Memory Usage: 11.2 MB, less than 95.86% of Python online submissions for Binary Tree Level Order Traversal II.

class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        q = collections.deque()
        res = []
        if not root:
            return res
        q.append((root,1))
        while q:
            nd,lvl = q.popleft()
            if len(res) < lvl:
                res.insert(0,[nd.val])
            else:
                res[0].append(nd.val)
                
            if nd.left:
                q.append((nd.left,lvl+1))
            if nd.right:
                q.append((nd.right,lvl+1))
        return res
