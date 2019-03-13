# This is top-down dp solution. Space complexity is not optimal.
# Can be optimised by bottom-up dp solution.
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        mp = {}
        def helper(i):
            if i < len(nums):
                if i not in mp:
                    mp[i] = max(nums[i] + helper(i+2), helper(i+1))
                return mp[i]
            else:
                return 0
        return helper(0)
