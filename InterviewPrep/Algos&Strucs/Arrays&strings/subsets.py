# https://leetcode.com/problems/subsets/

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def binary_rep(num):
            ret = []
            while num != 0:
                ret.append(num % 2)
                num = num // 2
            return ret
        ret = []
        for i in range(2**len(nums)):
            mask = binary_rep(i)
            ret.append([nums[j] for j in range(len(mask)) if mask[j] == 1])
        return ret
