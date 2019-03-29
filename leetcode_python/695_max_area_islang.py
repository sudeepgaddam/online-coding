class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        ls = [[-1,0],[1,0],[0,-1],[0,1]]
        def helper(i,j, res):
            for x in ls:
                newX = i+x[0]
                newY= j+x[1]
                if newX>=0 and newY>=0 and newX<rows and newY<cols and (grid[newX][newY]==1):
                    # print newX, newY
                    grid[newX][newY]=0
                    res = helper(newX,newY,res+1)
            return res
            
        
        rows = len(grid)
        if not rows:
            return 0
        cols = len(grid[0])
        maxRes = 0
        for i in range(0,rows):
            for j in range(0,cols):
                if grid[i][j]:
                    grid[i][j]=0
                    maxRes= max(helper(i,j,1),maxRes)
        return maxRes
