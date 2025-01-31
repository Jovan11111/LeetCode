class Solution(object):    
    def findNumbers(self, nums):
        ret = 0
        for el in nums:
            if((el > 9 and el < 100) or (el > 999 and el < 10000) or (el > 99999)):
                ret += 1
        return ret
        