class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        mp = {}
        for i,num in enumerate(nums):
            if num not in mp:
                mp[num] = i
            else:
                if abs(mp[num] - i) <= k:
                    return True
                mp[num] = i
        return False
