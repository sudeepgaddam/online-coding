class Solution(object):
    def decodeString(self, inp):
        """
        :type s: str
        :rtype: str
        """
        res =''
        num = ''
        st = []
        for i,ch in enumerate(inp):
            if ch == '[':
                st.append([int(num),''])
                num = ''
            elif ch.isdigit():
                num+=ch
            elif ch == ']':
                tmp = st.pop()
                ss =  ''.join(tmp[1] * tmp[0])
                if any(st): 
                    st[-1][1] += ss
                else:
                    res += ss
            else:
                if any(st):
                    st[-1][1] += ch
                else:
                    res = res + (ch)
        return res
