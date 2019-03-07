class MinStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.st  = []
        self.min_st = []


    def push(self, x):
        """
        :type x: int
        :rtype: None
        """        
        self.st.append(x)
        if not self.min_st or x<=self.min_st[-1]:
            self.min_st.append(x)

        

    def pop(self):
        """
        :rtype: None
        """
        num = self.st[-1]
        if num == self.min_st[-1]:
            self.min_st.pop()
        self.st.pop()
        return num


    def top(self):
        """
        :rtype: int
        """
        return self.st[-1]

    def getMin(self):
        """
        :rtype: int
        """
        return self.min_st[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
