# Using a single helper function, call it repetitively.
# Use previous result and return new result(list)
# Can be space optimised
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        def helper(d,ls):
            if not ls:
                ls.append('')
            rs = []
            for s in ls:
                for x in mp[d]:
                    rs.append(s+x)
            return rs
                    
        rs = []
        mp = {"2":"abc",
              "3":"def",
              "4":"ghi",
              "5":"jkl",
              "6":"mno",
              "7":"pqrs",
              "8":"tuv",
              "9":"wxyz"}
        for d in digits:
            rs = helper(d,rs)
        return rs
