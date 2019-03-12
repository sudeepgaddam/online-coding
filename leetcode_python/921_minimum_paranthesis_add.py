class Solution(object):
    def minAddToMakeValid(self, S):
        """
        :type S: str
        :rtype: int
        """
        opens = 0
        count = 0
        for x in S:
            if x == '(':
                opens +=1
            elif x == ')':
                if opens!=0:
                    opens-=1
                else:
                    count+=1
        return count+opens
