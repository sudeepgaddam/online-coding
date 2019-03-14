class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        res = [cost[0], cost[1]]
        for i in range(2,len(cost)):
            res.append(min(res[i-1], res[i-2]) + cost[i])
        return min(res[-1],res[-2])
