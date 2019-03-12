#Could not come up with idea on my own
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        st = []
        i=0
        for num in pushed:
            st.append(num)
            while st and st[-1] == popped[i]:
                st.pop()
                i+=1
                # print(i)
        return (len(popped)==i)
