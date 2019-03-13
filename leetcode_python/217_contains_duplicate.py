class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        mp = set()
        for num in nums:
            if num not in mp:
                mp.add(num)
            else:
                return True
        return False
