/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

*/


class Solution {
public:
    int titleToNumber(string s) {
        int s_size = s.size();
        int num = 0;
        for(int i=0;i<s_size;i++) {
            num = num*26 + (s[i] - 'A'+1);
        }
        return num;
    }
};
