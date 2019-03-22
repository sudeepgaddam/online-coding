# Uses O(n) space. Might get MLE. Need to optimise for space.
class Solution(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.mp = collections.defaultdict(list)
        for i,x in enumerate(nums):
            self.mp[x].append(i)

    def pick(self, target):
        """
        :type target: int
        :rtype: int
        """
        # ls = (self.mp[target])
        return random.choice(self.mp[target])
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.pick(target)
