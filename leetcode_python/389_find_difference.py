class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        mp =  collections.defaultdict(int)
        for ch in s:
            mp[ch]+=1
        for ch in t:
            mp[ch]-=1
        for k in mp.keys():
            if abs(mp[k]) == 1:
                return k
