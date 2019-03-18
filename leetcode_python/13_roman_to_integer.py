class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        val = {"I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000}
        res = val[s[0]]
        ch = s[0]
        for i in range(1,len(s)):
            if val[s[i]] > val[s[i-1]]:
                res =res - (2*val[s[i-1]])
            res += val[s[i]]
        return res
                
        
