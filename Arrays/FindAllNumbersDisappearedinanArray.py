class Solution(object):
    def findDisappearedNumbers(self, nums):
        helper = []
        for i in range(len(nums)):
            helper.append(0)
        ret = []
        for i in range(len(nums)):
            helper[nums[i]-1] += 1
        for i in range(len(helper)):
            if(helper[i] == 0):
                ret.append(i+1)
        return ret
        