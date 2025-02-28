class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        ret = 0
        counter = 0
        for el in nums:
            if el == 1:
                counter+=1
            else:
                ret = max(counter, ret)
                counter = 0
        return max(counter, ret)