# https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/

class Solution(object):
    def longestSubsequence(self, arr, difference):
        """
        :type arr: List[int]
        :type difference: int
        :rtype: int
        """
        hashMap = dict()
        for i in range(len(arr)):
            if arr[i] in hashMap:
                if arr[i] - difference in hashMap:
                    hashMap[arr[i]] = max(hashMap[arr[i]], hashMap[arr[i] - difference] + 1)
            else:
                if arr[i] - difference in hashMap:
                    hashMap[arr[i]] = hashMap[arr[i] - difference] + 1
                else:
                    hashMap[arr[i]] = 1
        
        return max(hashMap.values())

