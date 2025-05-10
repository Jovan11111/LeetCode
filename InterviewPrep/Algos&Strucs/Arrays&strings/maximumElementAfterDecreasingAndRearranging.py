# https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

class Solution(object):
    def maximumElementAfterDecrementingAndRearranging(self, arr):
        arr.sort()
        ret = len(arr)

        for i, el in enumerate(arr):
            if el == i + 1 - len(arr) + ret:
                continue
            if el > i + 1 - len(arr) + ret:
                continue
            else:
                ret -= 1
        return ret
        
