class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        i = 0
        res = ''
        sign = 1
        str = str.strip()
        if i<len(str) and (str[i] in ['-','+']):
            if str[i] == '-':
                sign = -1
            i+=1
        while i<len(str) and str[i].isdigit():
            res +=str[i]
            i+=1
        if not res.isdigit():
            res = 0
        else:
            res = int(res)*sign
        return min(2**31-1,max(-2**31,res))
