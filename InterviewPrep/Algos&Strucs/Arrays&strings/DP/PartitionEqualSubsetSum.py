# https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution(object):
    def canPartition(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if sum(nums) % 2 == 1:
            return False
        
        target_sum = sum(nums) / 2

        knapsack = [False] * (target_sum + 1)
        knapsack[0] = True
        for i in range(len(nums)):
            for j in range(len(knapsack)-1, nums[i]-1, -1):
                if knapsack[j-nums[i]] == True:
                    knapsack[j] = True
                    if j == len(knapsack) -1:
                        return True
        return False
        
