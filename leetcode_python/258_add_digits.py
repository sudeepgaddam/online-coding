class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        res = str(num)
        while len(res) > 1:
            num = 0
            for r in res:
                num+=int(r)
            res = str(num)
        return int(res)
