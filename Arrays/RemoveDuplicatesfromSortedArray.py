class Solution(object):
    def removeDuplicates(self, nums):
        helper = set()
        for el in nums:
            helper.add(el)
        helper = sorted(helper)
        for i, el in enumerate(helper):
            nums[i] = el
        return len(helper)
        