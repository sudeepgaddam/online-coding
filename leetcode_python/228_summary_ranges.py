class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        res = []
        def writer(mini,maxi):
            if mini==maxi:
                res.append(str(mini))
            else:
                res.append(str(mini)+"->" + str(maxi))
        if not nums:
            return []
        mini = nums[0]
        maxi = nums[0]
        for i in range(1,len(nums)):
            if nums[i] == (nums[i-1] + 1):
                maxi = nums[i]
            else:
                writer(mini,maxi)
                mini = nums[i]
                maxi = nums[i]
        writer(mini,maxi)
        return res
            
