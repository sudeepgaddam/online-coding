class Solution(object):
    def __init__(self):
        self.mp = {}
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n in self.mp:
            return self.mp[n]
        if n<3:
            self.mp[n] = n
            return self.mp[n]
        self.mp[n] =   self.climbStairs(n-1) + self.climbStairs(n-2)
        return self.mp[n]
