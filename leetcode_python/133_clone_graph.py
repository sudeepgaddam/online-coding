"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, neighbors):
        self.val = val
        self.neighbors = neighbors
"""
class Solution(object):
    def cloneGraph(self, node):
        """
        :type node: Node
        :rtype: Node
        """
        mp  = {}
        def helper(node):
            if node.val not in mp:
                a = Node(node.val,None)
                mp[node.val] = a
                ls = []
                for x in node.neighbors:
                    ls.append(helper(x))
                a.neighbors = ls
            return mp[node.val]
        return helper(node)
