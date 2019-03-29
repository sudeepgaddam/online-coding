class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        ls = s.split()
        for i,item in enumerate(ls):
            ls[i] = item[::-1]
        return ' '.join(ls)
