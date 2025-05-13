# https://leetcode.com/problems/smallest-range-i/description/

class Solution(object):
    def smallestRangeI(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        return max(max(nums) - min(nums) - 2*k, 0)
