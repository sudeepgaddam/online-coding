class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        """
        1,2,3,4 -> 1,2,4,3
        1,3,4,2 -> 1,4,2,3 
        1,2,5,4,3 -> 1,3,2,4,5
        1,3,4,4 -> 1,4,3,4
        """
        i = len(nums)-1
        
        # Find i such that nums[i+1:] is in non-increasing order
        while i>0 and nums[i-1]>=nums[i]:
            i-=1
        i-=1
        if i==-1:
            nums[:] = reversed(nums[:])
            return
        j = len(nums)-1
        
        # Find smallest num greater than nums[i] in (i+1,:)
        while j>i:
            if nums[j] > nums[i]:
                nums[i],nums[j] = nums[j],nums[i]
                break
            j-=1
        nums[i+1:] = reversed(nums[i+1:])
