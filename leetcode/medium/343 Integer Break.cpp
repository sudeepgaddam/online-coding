/*
Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.Show More Hint 
*/
//I have done DP solution, However there is a better solution with bit involved math
class Solution {
public:

    int rec(int n,vector<int> &dp) {
        int max_num=INT_MIN;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i<n;i++) {
            max_num = max(max_num,rec(n-i,dp)*i);
            max_num = max(max_num, (n-i)*i);
        }
        dp[n] = max_num;
        return dp[n];
        
    }
    int integerBreak(int n) {
        vector<int> dp(n+1,-1);
        dp[1] =1;
        dp[2] = 1;
        return rec(n,dp);
        
        
    }
};
