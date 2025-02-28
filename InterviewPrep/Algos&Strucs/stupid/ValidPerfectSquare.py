# https://leetcode.com/problems/valid-perfect-square/
import math
class Solution(object):
    def isPerfectSquare(self, num):
        return int(math.sqrt(num)) == math.sqrt(num)
