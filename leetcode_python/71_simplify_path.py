class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        strs = path.split('/')
        res = ''
        st = []
        # print(strs)
        for s in strs:
            if s=='/' or s =='.' or not s:
                1
            elif s == '..':
                if st:
                    st.pop()
            else:
                st.append(s)
        res = '/' + '/'.join(st)
        return res            
