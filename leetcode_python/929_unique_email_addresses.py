class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        st = set()
        for email in emails:
            firstPart,secondPart = email.split('@')
            res = ''
            for i,ch in enumerate(firstPart):
                if ch == '.':
                    continue
                elif ch == '+':
                    break
                else:
                    res+=ch
            st.add(res+'@'+secondPart)
        return len(st)
