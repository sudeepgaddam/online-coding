class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        maxLen = max(len(a),len(b))
        diffLen = abs(len(a)-len(b))
        
        def helper(a):
            for i in range(0,diffLen):
                a = '0' + a
            return a
        if len(a) < maxLen:
            a = helper(a)
        elif len(b) < maxLen:
            b = helper(b)
        
        a = a[::-1]
        b = b[::-1]
        res  = ''
        cary = 0
        for i in range(0,maxLen):
            sum = int(a[i]) + int(b[i]) + cary
            cary = sum/2
            sum = sum%2
            res +=str(sum)
        if cary:
            res+=str(cary)
        res =  res[::-1]
        return res
                
            
