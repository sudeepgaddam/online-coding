/*

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
*/
//This solution is not by me. I did DP solution which has memory limit exceeded. I like the below solution.

/*

Explanation:
Maybe we can consider this problem in another way. We consider n is a binary number.
When n is even, we just recursively divide by 2, it's the same as you.
When n is odd, we consider the tail number of the binary number n, for example, when the tail is 01 we should minus 1, and when the tail is 11 or 111, we should plus 1, to make it can be divided to 1 faster
*/
class Solution 
{
    int res = 0;
public:
    int integerReplacement(int n) 
    {
        if (n == 1)
            return res;
        if (n == 3)
        {
            res += 2;
            return res;
        }
        if (n == INT_MAX)
            return 32;
        
        res ++;
        if (n & 1)
            if ((n + 1) % 4 == 0)
                integerReplacement(n + 1);
            else
                integerReplacement(n - 1);
        else
            integerReplacement(n / 2);
            
        return res;
    }
};
