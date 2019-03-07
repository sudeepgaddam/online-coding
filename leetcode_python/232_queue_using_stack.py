class MyQueue(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.st1=[]
        self.st2=[]

    def push(self, x):
        """
        Push element x to the back of queue.
        :type x: int
        :rtype: None
        """
        self.st1.append(x)

    def pop(self):
        """
        Removes the element from in front of queue and returns that element.
        :rtype: int
        """
        if not any(self.st2):
            for x in (self.st1[::-1]):
                self.st2.append(x)
            self.st1=[]
        return self.st2.pop()
    def peek(self):
        """
        Get the front element.
        :rtype: int
        """
        if not any(self.st2):
            for x in (self.st1[::-1]):
                self.st2.append(x)
            self.st1=[]
        return self.st2[-1]


    def empty(self):
        """
        Returns whether the queue is empty.
        :rtype: bool
        """
        return not(self.st1 or self.st2)


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()
