# BFS solution.
# Todo: Union find solution
class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        def bfs(grid,i,j):
            incs = {(-1,0),(1,0),(0,1),(0,-1)}
            if grid[i][j] != '1':
                return
            q = collections.deque()
            q.append((i,j))
            while q:
                (i,j) = q.pop()
                for ind,el in enumerate(incs):
                    newX = i+el[0]
                    newY = j+el[1]
                    if newX>=0 and newY>=0 and newX<rows and newY<cols and grid[newX][newY] == '1':
                        grid[newX][newY] = '0'
                        q.append((newX,newY))
            return
        

        res =0 
        rows = len(grid)
        
        if not rows:
            return res
        cols = len(grid[0])
        for i in range(0,rows):
            for j in range(0,cols):
                if grid[i][j] == '1':
                    res+=1
                    bfs(grid,i,j)
        return res
                
