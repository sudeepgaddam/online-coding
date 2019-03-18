# T?T?F:5:3
# F?1:T?4:5
class Solution(object):
    def parseTernary(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        st = []
        i = len(expression)
        while i>0:
            i-=1
            if expression[i] =='?':
                i-=1
                n1 = st.pop()
                n2 = st.pop()
                if expression[i] == 'T':
                    st.append(n1)
                else:
                    st.append(n2)
            else:
                if expression[i] not in [':']:
                    st.append(expression[i])
        return st.pop()
