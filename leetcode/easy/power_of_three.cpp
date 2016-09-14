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

/*
72ms
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};
