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
