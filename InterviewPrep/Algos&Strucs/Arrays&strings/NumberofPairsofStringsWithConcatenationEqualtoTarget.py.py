# https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution(object):
    def numOfPairs(self, nums, target):
        ret = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == target:
                    ret += 1

                if nums[j] + nums[i] == target:
                    ret += 1
        return ret