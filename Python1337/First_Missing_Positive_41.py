class Solution(object):
    def firstMissingPositive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        x = len(nums)
        nums = [el for el in nums if el > 0]
        nums = list(dict.fromkeys(nums))
        y = len(nums);
        nums.sort();
        for i in range(len(nums)):
            if(nums[i] != i+1):
                return i+1;
        return y+1
        
