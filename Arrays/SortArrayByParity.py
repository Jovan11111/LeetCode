class Solution(object):
    def sortArrayByParity(self, nums):
        start = 0
        end = len(nums) - 1
        while(start <= end):
            if nums[start] % 2 == 1 and nums[end] % 2 == 0:
                nums[start], nums[end] = nums[end], nums[start]
            else:
                if nums[start] % 2 == 0:
                    start += 1
                if nums[end] % 2 == 1:
                    end -= 1
        return nums
        