class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        ret = [0] * len(nums)
        product = 1;

        for el in nums:
                if el == 0:
                    continue
                else:
                    product *= el

        if nums.count(0) == 1:
            ret[nums.index(0)] = product
        elif nums.count(0) == 0:
            ret = [int(product / num) for num in nums]
        
        return ret
        