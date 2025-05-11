# https://leetcode.com/problems/coin-change/submissions/1631372242/

class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        knapsack = [float('inf')] * (amount + 1)
        knapsack[0] = 0

        for i in range(len(coins)):
            for j in range(len(knapsack)):
                if j - coins[i] >= 0:
                    knapsack[j] = min(knapsack[j - coins[i]] + 1, knapsack[j])
        
        if knapsack[-1] == float('inf'):
            return -1
        return knapsack[-1]
