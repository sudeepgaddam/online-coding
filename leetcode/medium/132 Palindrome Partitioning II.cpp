/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.


*/


/*
Non- working solution
DP solution but not optimal solution
*/

class Solution {
public:
       bool isPalindrome(string s,int start, int end) {
           while(start < end) {
               if(s[start] != s[end]) return false;
               
               start++;
               end--;
               
           }
        return true;
    }

    int rec(int j, int k, vector<vector<int> > &dp, string s) {
        int min_ops = INT_MAX;
        
        if(isPalindrome(s,j,k)) return 0;
        for(int i=j;i<k;i++) {
            
            int tmp = dp[j][i] + dp[i+1][k];
            
            min_ops = min(tmp, min_ops);
        }
        
        return min_ops+1;
        
    }
    int minCut(string s) {
        
        int s_size = s.size();
        
        vector<vector<int> > dp(s_size,vector<int>(s_size,0));
        
        //Initialise matrix elements of size 1
        for(int i=0;i<s_size;i++) dp[i][i] =0;
        
        
        for(int L=2;L<=s_size;L++) {
            for(int j=0;j<s_size-L+1;j++) {
                
                int k = j+L-1;
                //Pass this j and k to another function which takes care of finding min
                dp[j][k] = rec(j,k,dp,s);
                
            }
            
        }
        
        return dp[0][s_size-1];
        
        
    }
};
