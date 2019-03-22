# Same solution works for both i and ii part of this problem

class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return False
        m = 0
        n = len(matrix[0])-1
        while(m>=0 and n>=0 and m<len(matrix) and n<len(matrix[0])):
            if target == matrix[m][n]:
                return True
            elif target> matrix[m][n]:
                m+=1
            elif target<matrix[m][n]:
                n-=1
        return False
