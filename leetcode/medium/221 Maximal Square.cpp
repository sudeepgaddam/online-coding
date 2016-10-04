/*


Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.


*/


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows ==0) return 0;
        int cols = matrix[0].size();
       vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));
    
        //Initialise the first row
       for(int i=0;i<cols;i++) 
            if(matrix[0][i]=='0') dp[0][i] =0;
            else dp[0][i] =1;
            
            
        //Initialise the first coloumn
        for(int i=0;i<rows;i++) 
            if(matrix[i][0]=='0') dp[i][0] =0;
            else dp[i][0] =1;       
       
       
        /*
            Go through the matrix, Size of square at [i][j] is dependent upon
            [i-1][j], [i-1][j-1], [i][j-1]
            It is intuitive to see when all of the above 3 are equal , Lets say n, and char[i][j]==1,
            You can increase the length of the square, It becomes n+1. 
            If they are not equal, Then u can only increase the minimum length by 1.
            It is the beatiful implementation of DP. Heavily inspired by Edit distance DP formulation
        */
        for(int i=1;i<rows;i++) {
            for(int j=1;j<cols;j++) {
                if(matrix[i][j]=='1')  {
                    dp[i][j] = 1 + min(min(dp[i-1][j],dp[i-1][j-1]),dp[i][j-1]);
                }
            }
        }
        
        int max_num=0;
        
        //Scan the dp matrix to get the max dimension
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                       max_num = max(max_num,dp[i][j]);
            }
        }
        return max_num*max_num;
        
    }

};
