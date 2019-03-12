class Solution(object):
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        def calc(num1, num2, op):
            if op=='+':
                return num1 + num2
            elif op =='*':
                return num1 * num2
            elif op=='/':
                sign = ( num1/abs(num1) if num1!=0 else 1) * (num2/abs(num2))
                res = abs(num1)/abs(num2)
                return sign * res
            elif op=='-':
                return num1-num2
        st = []
        for s in tokens:
            if s not in ["+","-","*","/"]:
                num = int(s)
                st.append(num)
            else:
                num1 = st.pop()
                num2 = st.pop()
                res = calc(num2,num1, s)
                # print(res)
                st.append(res)
        return st[-1]
                
