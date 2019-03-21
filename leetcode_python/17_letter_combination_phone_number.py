class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def helper():
            if not res:
                res.append('')
            i=0
            for i,d in enumerate(digits):
                while len(res[0])!=(i+1):
                    s = res.pop(0)
                    for x in mp[d]:
                        res.append(s+x)
                    
        res = []
        mp = {"2":"abc",
              "3":"def",
              "4":"ghi",
              "5":"jkl",
              "6":"mno",
              "7":"pqrs",
              "8":"tuv",
              "9":"wxyz"}
        if digits:
            helper()
        return res
