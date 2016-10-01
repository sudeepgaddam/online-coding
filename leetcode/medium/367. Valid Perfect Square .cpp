/*

Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False

*/

class Solution {
public:
    bool isPerfectSquare(int n) {
        
        long a=1;
        long num = n;
        while(1) {
            if(a*a==num) return true;
            if(a*a-num>0) break;
            a=a<<1;
        }
        
        
        for(long i=a;i>=a/2;i--) {
            
            if(i*i==num) return true;
        }
        
        return false;
        
    }
};
