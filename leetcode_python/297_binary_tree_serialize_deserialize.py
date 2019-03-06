# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        res = []
        def helper(root):
            if not root:
                res.append('#')
            else:
                res.append(str(root.val))
                helper(root.left)
                helper(root.right)
        
        helper(root)
        return ' '.join(res)
            
    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def helper(data):
            n = next(data)
            if n=='#':
                return None
            node = TreeNode(n)
            node.left = helper(data)
            node.right = helper(data)
            return node        
        vals = data.split()
        iteration = iter(vals)

        return helper(iteration)
            
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
