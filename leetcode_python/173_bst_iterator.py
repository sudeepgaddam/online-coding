# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.root = root
        curr = self.root
        self.st = []
        while(curr):
            self.st.append(curr)
            curr = curr.left

    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        nd = self.st.pop()
        num = nd.val
        if nd.right:
            nd = nd.right
            while nd:
                self.st.append(nd)
                nd = nd.left            
        return num

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return (any(self.st))


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
