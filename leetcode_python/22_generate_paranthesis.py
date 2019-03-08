class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        res=[]
        def helper(parStr, n, currOpen, currClosed):
            if len(parStr) == 2*n:
                res.append(parStr)
                return
            if currOpen < n:
                helper(parStr+'(', n, currOpen+1, currClosed)
            if currClosed < currOpen:
                helper(parStr+')', n, currOpen, currClosed+1)

        
        helper('', n, 0,0)
        return res
