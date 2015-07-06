/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int sum=0;
        
        int k=1;
        while(n/pow(5,k)) {
            sum+=(n/pow(5,k));
            k++;
        }
        
        return sum;
        
    }
};
