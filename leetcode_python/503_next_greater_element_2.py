class Solution(object):
    def nextGreaterElements(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        st = []
        res = [-1] * len(nums)
        nums+=(nums[:-1])
        for i,num in enumerate(nums):
            while st and nums[st[-1]] < nums[i]:
                res[st.pop()] = nums[i]
            if i < len(res):
                st.append(i)
        return res
                
