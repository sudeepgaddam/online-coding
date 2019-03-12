class Solution(object):
    def scoreOfParentheses(self, S):
        """
        :type S: str
        :rtype: int
        """
        st = []
        res = 0
        for ch in S:
            if ch == '(':
                st.append(res)
                res=0
            else:
                # print(res,st)
                res += st.pop() + max(res,1)
        return res
