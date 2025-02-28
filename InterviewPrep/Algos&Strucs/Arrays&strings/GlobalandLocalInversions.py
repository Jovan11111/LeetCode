# https://leetcode.com/problems/global-and-local-inversions/

class Solution(object):
    def isIdealPermutation(self, nums):
        for i, el in enumerate(nums):
            if el != i and el + 1 != i and el - 1 != i:
                return False
        return True