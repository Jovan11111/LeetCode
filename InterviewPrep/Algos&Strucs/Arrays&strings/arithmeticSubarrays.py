# https://leetcode.com/problems/arithmetic-subarrays/description/

class Solution(object):
    def checkArithmeticSubarrays(self, nums, l, r):
        """
        :type nums: List[int]
        :type l: List[int]
        :type r: List[int]
        :rtype: List[bool]
        """
        def isArithmetic(nums):
            diff = nums[1] - nums[0]
            for i in range(len(nums)-1):
                if nums[i+1] - nums[i] != diff:
                    return False
            return True

        return [isArithmetic(sorted(nums[l[i]: r[i] + 1])) for i in range(len(l))]
