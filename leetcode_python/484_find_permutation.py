class Solution(object):
    def findPermutation(self, s):
        """
        :type s: str
        :rtype: List[int]
        """
        l = len(s)
        res = []
        st = []
        for i,ch in enumerate(s):
            if ch == "I":
                st.append(i+1)
                if any(st):
                    while st:
                        res.append(st.pop())
            else:
                st.append(i+1)
        st.append(l+1)
        if any(st):
            while st:
                res.append(st.pop())

        return res
