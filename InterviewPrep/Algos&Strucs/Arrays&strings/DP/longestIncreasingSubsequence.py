# https://leetcode.com/problems/longest-increasing-subsequence/

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        dp = dict()

        def biggestValueOfTheSmallerElInDP(el):
            ret = 0
            for k, v in dp.items():
                if k < el and ret < v:
                    ret = v
            return ret

        for el in nums:
            if el in dp:
                dp[el] = max(biggestValueOfTheSmallerElInDP(el) + 1, dp[el])
            else:
                dp[el] = biggestValueOfTheSmallerElInDP(el) + 1
        
        return max(dp.values())
    
