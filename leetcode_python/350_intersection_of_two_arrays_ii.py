class Solution(object):
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        mp = collections.defaultdict(int)
        res=[]
        for num in nums1:
            mp[num]+=1
        for num in nums2:
            if mp[num] > 0:
                res.append(num)
                mp[num]-=1
        return res
