/*

A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.


*/

class Solution {
public:
    int rec(int i, int j, vector<vector<int>>& dp) {
        if(i==0 && j==0 ) return 1;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if(i==0) {
            dp[i][j] = rec(i,j-1, dp);
            return dp[i][j];
        }
        if(j==0) {
            dp[i][j] = rec(i-1,j, dp);
            return dp[i][j];
        }
        dp[i][j] = rec(i-1,j,dp) + rec(i,j-1, dp) ;
        return dp[i][j];
        
    }


    int uniquePaths(int m, int n) {
        if(m==0) return 0;
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));
        return rec(m-1,n-1, dp);
    }
};
