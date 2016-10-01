/*

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.



*/

class Solution {
public:

    int rec(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        

        if(i==0 && j==0 ) return grid[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];


        if(i==0) {
            dp[i][j] = grid[i][j] + rec(i,j-1,grid, dp);
            return dp[i][j];
        }
        
        if(j==0) {
            dp[i][j] = grid[i][j] + rec(i-1,j, grid, dp);
            return dp[i][j];
        }

        dp[i][j] = grid[i][j] + min(rec(i-1,j,grid,dp), rec(i,j-1,grid, dp)) ;
        return dp[i][j];
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m==0) return 0;
        int n= grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        return rec(m-1,n-1,grid, dp);
    }
};
