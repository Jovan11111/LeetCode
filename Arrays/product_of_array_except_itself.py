# https://leetcode.com/problems/product-of-array-except-self/
# Moje resenje
# Optimalno al koristi deljenje, nije poenta da koristi deljenje
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
        return 

# Najbolje resenje
# Jako pametno, u prvom prolazu racuna proizvod levo od nekog elementa, i onda u drugom prolazu se racuna proizvod desno od tog elementa, i onda se ta dva pomnoze
class Solution(object):
    def productExceptSelf(self, nums):
        n = len(nums)
        result = [1] * n  # Početna vrednost

        # Proizvod elemenata levo od svakog elementa
        left_product = 1
        for i in range(n):
            result[i] = left_product
            left_product *= nums[i]

        # Proizvod elemenata desno od svakog elementa
        right_product = 1
        for i in range(n - 1, -1, -1):
            result[i] *= right_product
            right_product *= nums[i]

        return result
