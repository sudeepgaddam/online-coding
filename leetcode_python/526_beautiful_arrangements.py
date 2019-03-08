class Solution(object):
    def countArrangement(self, N):
        """
        :type N: int
        :rtype: int
        """
        def isValid(num,i):
            return (num%i==0) or (i%num ==0)
        def helper(N, used, currIndex):
            if currIndex  == 0:
                self.res+=1
            for x in range(N, 0,-1):
                if used[x]!=1 and isValid(x, currIndex):
                    used[x] = 1
                    helper(N,used, currIndex-1)
                    used[x] = 0
        self.res = 0
        used = [0]* (N+1)
        helper( N, used, N)
        return self.res
