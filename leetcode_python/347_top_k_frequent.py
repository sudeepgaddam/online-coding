class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # Following method is by doing sort based on frequency and selecting top k
        # This is amazingly short code. Thanks to map, list slicing and lambdas
        res = []
        mp = collections.defaultdict(int)
        for num in nums:
            mp[num]+=1
        res = map(lambda x:(x,mp[x]), (mp.keys()))
        res.sort(key=lambda x:x[1],reverse=True)
        return map(lambda x:x[0],res[0:k])
