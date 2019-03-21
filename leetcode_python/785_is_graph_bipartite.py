# Implementation is based off coloring algo.
# Color nodes with two colors. If at any given point, neighbors color and node's color 
# turn out to be same, then bipartite graph doesn't exist.

class Solution(object):
    def isBipartite(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: bool
        """
        color = {}
        for node in range(len(graph)):
            if node not in color:
                st = [node]
                color[node] = 0
                while st:
                    nd = st.pop()
                    for n in graph[nd]:
                        if n not in color:
                            color[n] = color[nd] ^ 1
                            st.append(n)
                        elif color[n] == color[nd]:
                            return False
        return True
