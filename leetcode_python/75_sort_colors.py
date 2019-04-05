class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        counter_arr=[0,0,0]
        for num in nums:
            counter_arr[num]+=1
        start=0
        for ind, num in enumerate(counter_arr):
            for i in range(start,start+num):
                nums[i] = ind
            start+=num
        return
