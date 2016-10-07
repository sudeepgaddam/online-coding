/*
All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].

*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        set<string> res;
        if(s.size()<10) return vector<string>(res.begin(), res.end());;
                    map<string,int> mp;

        for(int i=0;i<=s.size()-10;i++) {
            auto needle = s.substr(i,10);
            mp[needle]++;
        }
        
        for(int i=0;i<=s.size()-10;i++) {
            auto needle = s.substr(i,10);
            if((res.find(needle)==res.end()) && (mp[needle]>1) )
                res.insert(needle);
        }
        return vector<string>(res.begin(), res.end());
    }
};
