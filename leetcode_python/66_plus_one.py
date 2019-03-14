class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry=1        
        l = len(digits)-1
        while carry==1 and l>=0:
            digits[l]+=1
            carry,digits[l] = digits[l]/10,digits[l]%10
            l-=1
        if carry ==1:
            digits = [1] + digits
        return digits
