class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        st=[]
        mp = {'(':')','[':']','{':'}'}
        for ch in s:
            if ch in mp.keys():
                st.append(ch)
            elif ch in ['}',')',']']:
                if st and ch == mp[st[-1]]:
                    st.pop()
                else:
                    return False
        return not(st)
