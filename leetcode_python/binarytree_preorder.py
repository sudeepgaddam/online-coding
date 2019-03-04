# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# Non trivial Iterative solution
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res=[]
        st=[]
        if not root:
            return res
        st.append(root)
        while st:
            res.append(st[-1].val)
            nd = st.pop()
            if nd.right:
                st.append(nd.right)
            if nd.left:
                st.append(nd.left)
        return res
