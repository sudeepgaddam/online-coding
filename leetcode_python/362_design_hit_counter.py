class HitCounter(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.deq = collections.deque()

    def hit(self, timestamp):
        """
        Record a hit.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: None
        """
        if self.deq:
            if self.deq[-1][0] == timestamp:
                self.deq[-1]=(self.deq[-1][0], self.deq[-1][1]+1)
            else:
                self.deq.append((timestamp,1))
            while timestamp - self.deq[0][0] >= 300:
                self.deq.popleft()
        else:
            self.deq.append((timestamp,1))

    def getHits(self, timestamp):
        """
        Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity).
        :type timestamp: int
        :rtype: int
        """
        if self.deq:
            while self.deq and timestamp - self.deq[0][0] >= 300:
                self.deq.popleft()
            sum = 0
            for x in self.deq:
                sum+=x[1]
            return sum
            # for num in self.deq:
        return 0
                




# Your HitCounter object will be instantiated and called as such:
# obj = HitCounter()
# obj.hit(timestamp)
# param_2 = obj.getHits(timestamp)
