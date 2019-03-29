class Solution(object):
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        i = 0
        res = ''
        sign = 1
        INT_MIN = -(1<<31)
        INT_MAX = (-INT_MIN) - 1
        # print INT_MAX
        while i<len(str) and str[i]==' ':
            i+=1
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
        res = min(INT_MAX,max(INT_MIN,res))
        return res
        
