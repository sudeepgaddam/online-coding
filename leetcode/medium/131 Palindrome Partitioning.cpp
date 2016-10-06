/*

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]

*/


/*
Typical Backtracking question, Recursion with For loop
Not so hard question 
*/
class Solution {
public:
   bool isPalindrome(string s, int start, int end) {
        if(end >= s.size()) return false;
        while(start < end) {
          if(s[start++] != s[end--]) return false;
        }
        return true;
    }
    
    void rec(string s, int start, int end, vector<string> curr, vector<vector<string>> &res) {
        if(start > (end) )
          res.push_back(curr);

        for(int i=start;i<=end;i++) {
            auto new_curr = curr;
            if(isPalindrome(s, start, i)){ 
                new_curr.push_back(s.substr(start, i-start+1));
                rec(s, i+1, end, new_curr,res);
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> a ; 
        rec(s, 0, s.size()-1, a, res);
        return res;  
    }
};
