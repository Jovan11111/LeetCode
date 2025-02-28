class Solution(object):
    def sortedSquares(self, nums):
        return sorted([el**2 for el in nums])
        