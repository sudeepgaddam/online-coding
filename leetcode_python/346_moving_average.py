class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.sum = 0
        self.nums = 0
        self.size = size
        self.deq = collections.deque()

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.deq.append(val)
        self.nums += 1
        size = self.nums
        if self.nums > self.size:
            self.sum-=self.deq.popleft()
            size = self.size
        self.sum += val
        return float(self.sum)/size


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)
