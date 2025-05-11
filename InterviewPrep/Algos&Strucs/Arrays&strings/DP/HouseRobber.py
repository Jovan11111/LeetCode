# https://leetcode.com/problems/house-robber/

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def robHouse(i, curAmount):
            if i > len(nums) - 1:
                return curAmount 
            if i == len(nums) - 1:
                return curAmount + nums[i]
            curAmount += nums[i]
            return max(robHouse(i + 2, curAmount), dontRobHouse(i + 1, curAmount))

        def dontRobHouse(i, curAmount):
            if i > len(nums) - 1:
                return curAmount
            if i == len(nums) - 1:
                return curAmount

            return max(robHouse(i + 1, curAmount), dontRobHouse(i+1, curAmount))

        if len(nums) == 1:
            return nums[0]
        if len(nums) == 0:
            return 0

        dp = [0] * len(nums)
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            dp[i] = max(dp[i-1], dp[i-2] + nums[i])
        return dp[-1]
        
