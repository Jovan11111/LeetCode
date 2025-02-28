class Solution(object):
    def thirdMax(self, nums):
        first = float('-inf')
        second = float('-inf')
        third = float('-inf')
        for el in nums:
            if el == first or el == second or el == third:
                continue
            if el > first:
                third = second
                second = first
                first = el
            elif el > second:
                third = second
                second = el
            elif el > third:
                third = el
        if third == float('-inf'):
            return first
        else:
            return third
        