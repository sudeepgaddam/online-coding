class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        self.res = []
        def helper(nums, curr):
            # print(nums,curr)
            if curr == len(nums):
                self.res.append([x for x in nums])
                return
            for i in range(curr,len(nums)):
                nums[curr], nums[i] = nums[i], nums[curr]
                helper(nums, curr+1)
                nums[curr], nums[i] = nums[i], nums[curr]

        helper(nums,0)
        return self.res
