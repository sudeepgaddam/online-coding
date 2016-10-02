/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.



*/

class Solution {
public:
    int rec(int i, int j,vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
      
        if(obstacleGrid[i][j]==1) {
            dp[i][j] = 0;
            return 0;
        }
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(i==0) {
            dp[i][j] = rec(i,j-1,obstacleGrid, dp);
            return dp[i][j];
        }
        if(j==0) {
            dp[i][j] = rec(i-1,j,obstacleGrid, dp);
            return dp[i][j];
        }
        dp[i][j] = rec(i-1,j,obstacleGrid,dp) + rec(i,j-1,obstacleGrid, dp) ;
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m==0) return 0;
        int n= obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        if(obstacleGrid[0][0]==0)
            dp[0][0] = 1;
        else dp[0][0] = 0;

        return rec(m-1,n-1, obstacleGrid, dp);

        
    }
};
