class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        mp = {}
        res = [0] * (num+1)
        for x in range(1,num+1):
                res[x] = ((x&1) + res[x>>1])
        return res
