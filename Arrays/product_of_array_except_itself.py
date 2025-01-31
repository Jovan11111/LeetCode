"""
My solution
"""
class Solution(object):
    def productExceptSelf(self, nums):
        full_product = 1
        zeros_occur = 0
        for el in nums:
            if(el == 0):
                zeros_occur = zeros_occur + 1
            else:
                full_product = full_product * el
                
        for i in range(len(nums)):
            if(nums[i] == 0):
                if(zeros_occur > 1):
                    nums[i] = 0
                else:
                    nums[i] = full_product
            else:
                if(zeros_occur > 0):
                    nums[i] = 0
                else:
                    nums[i] = full_product / nums[i]
        return nums
    
"""
Comments
"""