class LargerNumKey(str):
    def __lt__(x, y):
        return x+y > y+x

class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        nums = map(str,nums)
        nums.sort(key=LargerNumKey)
        return '0' if nums[0]=='0' else (''.join(nums))
        
