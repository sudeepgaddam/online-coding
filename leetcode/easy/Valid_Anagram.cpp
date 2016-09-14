/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?

*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0},b[26]={0};
        for (auto x:s) a[x-'a']++;
        for (auto x:t)b[x-'a']++;
        for (int i=0;i<26;i++) if (a[i]!=b[i]) return false;
        return true;
    }
};
