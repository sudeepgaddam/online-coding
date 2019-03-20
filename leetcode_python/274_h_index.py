class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        # print citations
        l = len(citations)
        for i in range(l-1,-1,-1):
            if citations[i] >= i+1:
                return i+1
        return 0
        
