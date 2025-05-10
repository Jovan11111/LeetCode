# https://leetcode.com/problems/harshad-number/description/

class Solution(object):
    def sumOfTheDigitsOfHarshadNumber(self, x):
        return sum([int(c) for c in [c for c in str(x)]]) if x % sum([int(c) for c in [c for c in str(x)]]) == 0 else -1
