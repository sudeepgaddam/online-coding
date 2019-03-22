class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        if not matrix:
            return 0
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

    # Alternative solution
    class Solution(object):
        def searchMatrix(self, matrix, target):
            """
            :type matrix: List[List[int]]
            :type target: int
            :rtype: bool
            """
            def searchRow(row,start,end):
                while start <= end:
                    mid = start+(end-start)/2
                    if target < matrix[row][mid]:
                        end = mid -1
                    elif target == matrix[row][mid]:
                        return True
                    else:
                        start = mid + 1
                return False

            if not matrix or len(matrix[0])==0:
                return 0
            n = len(matrix[0])-1
            start = 0
            end = len(matrix) -1

            while start <= end:
                mid = start+(end-start)/2
                if target >= matrix[mid][0] and target <=matrix[mid][n]:
                    return searchRow(mid,0,n)
                elif target < matrix[mid][n]:
                    end = mid -1
                else:
                    start = mid + 1
