# Extension of house robber problem. Except that houses are in circular now.
# Trick is to compute max(max robbery by including first house and excluding last, 
#                         max robbery by excluding first house and including last)
# Because both first and last can't be included as houses are circular.


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def helper(i,nums,mp):
            if i < len(nums):
                if i not in mp:
                    mp[i] = max(nums[i] + helper(i+2,nums,mp), helper(i+1,nums,mp))
                return mp[i]
            else:
                return 0
        if len(nums)==1:
            return nums[0]
        return max(helper(0,nums[1:],{}), helper(0,nums[:-1],{}))
