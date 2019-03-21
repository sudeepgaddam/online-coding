class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        count=0
        x = x^y
        while(x):
            count+=(x&1)
            x = x >> 1
        return count
