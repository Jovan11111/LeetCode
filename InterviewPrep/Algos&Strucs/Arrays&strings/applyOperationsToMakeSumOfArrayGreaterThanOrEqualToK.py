# https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/

class Solution(object):
    def minOperations(self, k):
        return min([i + ((k + i) // (i + 1) - 1) for i in range(k)])
