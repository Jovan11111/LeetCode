# https://leetcode.com/problems/combination-sum-ii/description/

class Solution(object):
    def combinationSum2(self, candidates, target):
        ans = []
        ds = []
        candidates.sort()


        def findCombination(ind, target):
            if target == 0:
                ans.append(ds[:])
                return
            for i in range(ind, len(candidates)):
                if i > ind and candidates[i] == candidates[i - 1]:
                    continue
                if candidates[i] > target:
                    break
                ds.append(candidates[i])
                findCombination(i + 1, target - candidates[i])
                ds.pop()


        findCombination(0, target)
        return ans
        
