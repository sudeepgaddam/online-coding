"""
Based on discussion in elements of programming interviews.
Powerful inference: computing backwards to get max profit if making a second buy on day i
and thus summing with single transaction maxProfit(i-1) which yields overall max.
on last day, first day second purchase can't be done.

Lesson learnt: Powerful inferences make for simple solutions.

Time complexity: O(n)
space complexity: O(1)

Improvements: space complexity can be optimised.
"""
class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        arr = [0] * len(prices)
        minSoFar = sys.maxint
        maxProfit = 0
        for i in range(len(prices)):
            minSoFar = min(minSoFar,prices[i])
            maxProfit = max(maxProfit,prices[i]-minSoFar)
            arr[i] = maxProfit
        maxSoFar = -(sys.maxint)
        for i in range(len(prices)-1,0,-1):
            maxSoFar = max(maxSoFar,prices[i])
            maxProfit = max(maxProfit, maxSoFar-prices[i] + arr[i-1])
        return maxProfit
