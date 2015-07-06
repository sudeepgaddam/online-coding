/*
 Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome. 
*/


class Solution {
public:
    bool isPalindrome(string s) {
        int last = s.size()-1;
        
        int i=0;
        int k=last;
        while(i<k)         {   
            if (!isalnum(s[i])){i++;continue;}
            if (!isalnum(s[k])){k--;continue;}
            if (tolower(s[i]) != tolower(s[k])) {return false;}
            i++;
            k--;
        }
        return true;
    }
};
