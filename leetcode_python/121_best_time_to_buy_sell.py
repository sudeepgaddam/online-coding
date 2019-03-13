class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        mn = sys.maxint
        prof = 0
        for price in prices:
            if price < mn:
                mn = price
            prof = max(prof,price-abs(mn))
        return prof
