/*
Write an algorithm to determine if a number is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Example: 19 is a happy number

    12 + 92 = 82
    82 + 22 = 68
    62 + 82 = 100
    12 + 02 + 02 = 1

*/

class Solution {
public:


    int getDigits(std::vector<int> &digits, int value){
        
        int sum=0;
        for( ; value > 0 ; value /= 10 ) digits.push_back( value%10 ) ;
    
        for (int i=0;i<digits.size();i++) {
             sum += (digits[i]*digits[i]);
        }
        return sum;
    }
    bool isHappy(int value) {
        
        std::vector<int> digits ;
        int count = 0;
        while(1){
        if (count++>1000)return false;    
        
        value = getDigits(digits,value);
        if (value==1){return true;}
        digits.clear();
        }
    }
};
