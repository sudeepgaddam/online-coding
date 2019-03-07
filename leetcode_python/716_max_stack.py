class MaxStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.st1  = []
        self.max_st = []

    def push(self, x):
        """
        :type x: int
        :rtype: None
        """
        self.st1.append(x)
        if not self.max_st or x>=self.max_st[-1]:
            self.max_st.append(x)

    def pop(self):
        """
        :rtype: int
        """
        num = self.st1[-1]
        if num == self.max_st[-1]:
            self.max_st.pop()
        self.st1.pop()
        return num
                

    def top(self):
        """
        :rtype: int
        """
        return self.st1[-1]

    def peekMax(self):
        """
        :rtype: int
        """
        return self.max_st[-1]

    def popMax(self):
        """
        :rtype: int
        """
        tmp_st = []
        
        while(self.st1[-1] != self.max_st[-1]):
            n = self.st1.pop()
            tmp_st.append(n)
            
        self.st1.pop()
        n = self.max_st.pop()
        
        while tmp_st:
            if not self.max_st or tmp_st[-1]>=self.max_st[-1]:
                self.max_st.append(tmp_st[-1])
            self.st1.append(tmp_st.pop())
        return n



# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
