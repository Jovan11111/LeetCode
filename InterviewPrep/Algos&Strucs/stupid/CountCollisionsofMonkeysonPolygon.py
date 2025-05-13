# https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/

class Solution(object):
    def monkeyMove(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        MOD = 10 ** 9 + 7
        return (pow(2, n, MOD) - 2) % MOD
