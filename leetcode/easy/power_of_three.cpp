/*
72ms
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
    if(n>1)
        while(n%3==0) n /= 3;
    return n==1;
    }
};

/*
68ms
*/
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1) return true;
        if(n==0 || n%3) return false;
        return (isPowerOfThree(n/3));
    }
};
