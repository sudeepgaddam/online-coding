/*

Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.

*/


/*
Not the most optimised solution but correct solution

*/
class Solution {
public:
    int longestPalindrome(string s) {
        
        map<char,int> count;
        
        for(auto a:s) count[a]++;
        bool odd = false;
        int length = 0;
        for(auto a: count) {
            if(count[a.first]%2){
                odd = true;
                length+=(a.second-1);
            }
            else length+=a.second;
            
        }
        
        return length+(odd==true);
    }
};
