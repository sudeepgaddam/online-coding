class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """
        res = []
        distances = map(lambda (i,x):[x[0]*x[0] + x[1]*x[1],i],enumerate(points))
        distances.sort(key=lambda x: x[0])
        # print(distances)
        for i in range(0,K):
            res.append(points[distances[i][1]])
        return res
