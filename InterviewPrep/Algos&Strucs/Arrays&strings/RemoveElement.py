class Solution(object):
    def removeElement(self, nums, val):
        helper = []
        counter = 0
        for el in nums:
            if el == val:
                counter += 1
            else:
                helper.append(el)
        for i in range(len(helper)):
            nums[i] = helper[i]
        return len(helper)
        