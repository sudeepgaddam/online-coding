class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.cumSum = [0]
        for num in nums:
            self.cumSum.append(num + self.cumSum[-1])

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        return self.cumSum[j+1] - self.cumSum[i]


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
