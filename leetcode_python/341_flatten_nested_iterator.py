# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger(object):
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class NestedIterator(object):

    def __init__(self, nestedList):
        """
        Initialize your data structure here.
        :type nestedList: List[NestedInteger]
        """
        self.nestedStack = [[nestedList,0]]

    def next(self):
        """
        :rtype: int
        """
        # print len(self.nestedStack[-1])
        self.hasNext()
        ll, i = self.nestedStack[-1]
        num = ll[i].getInteger()
        # print(num)
        self.nestedStack[-1][1]+=1
        return num
        # if self.nestedStack[-1][1] < len(self.nestedStack[-1][0]):
        #     if self.nestedStack[-1][0][self.currInd].isInteger():
        #         num = self.nestedStack[-1][0][self.currInd].getInteger()
        #         self.currInd += 1
        #         return num   
        #     else:
        #         nestedPush(self.nestedStack[-1][0][self.currInd])


    def hasNext(self):
        """
        :rtype: bool
        """
        # i = 0
        while self.nestedStack:
            # i+=1
            ll, i = self.nestedStack[-1]
            if i >= len(ll):
                # print("Popping")
                self.nestedStack.pop()
            else:
                if ll[i].isInteger():
                    # print("Integer", ll[i].getInteger())
                    return True
                else:
                    # print("Appending",ll[i].getList())
                    self.nestedStack[-1][1] += 1
                    self.nestedStack.append([ll[i].getList(),0])
        return False

# Your NestedIterator object will be instantiated and called as such:
# i, v = NestedIterator(nestedList), []
# while i.hasNext(): v.append(i.next())
