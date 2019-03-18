class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        curr =0
        nz = curr
        while curr< len(nums):
            if nums[curr]!=0:
                nums[nz] = nums[curr]
                nz+=1
            curr+=1
        while nz< len(nums):
            nums[nz] = 0
            nz+=1
