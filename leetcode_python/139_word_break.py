class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        mp={}
        def helper(s,start):
            if start == len(s):
                return True
            if start in mp:
                return mp[start]
            for i in range(start+1,len(s)+1):
                # print(s[start:i],i)
                if s[start:i] in wordDict:
                    if helper(s,i):
                        mp[start] = True
                        return True
            mp[start] = False
            return mp[start]
        return helper(s,0)
