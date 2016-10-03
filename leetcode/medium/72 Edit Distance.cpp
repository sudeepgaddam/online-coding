/*

Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character


*/

/*
https://www.youtube.com/watch?v=We3YDTzNXEk&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=8

Go Tushar Roy..Amazing videos

https://discuss.leetcode.com/topic/17639/20ms-detailed-explained-c-solutions-o-n-space

*/
class Solution {
public:

    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int> > dp(size1+1, vector<int>(size2+1,INT_MAX));
        for(int j=1;j<=size2;j++) dp[0][j] = j;
        for(int j=1;j<=size1;j++) dp[j][0] = j;
        dp[0][0] =0;
        
        for (int i = 1; i <= size1; i++) {
            for (int j = 1; j <= size2; j++) {
                if (word1[i - 1] == word2[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
            }
        }

        return dp[size1][size2];
    }
};
