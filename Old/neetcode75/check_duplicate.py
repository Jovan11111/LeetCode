class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        for el in nums:
            if nums.count(el) > 1:
                return True
        return False

"""
Resenja:
- Brute force - bzvz
- Sortiranje - O(n logn) za sortiranje, posle se prodje i posmatraju se samo susedni elementi
- Hashset, ide se kroz niz, ako element nije u nizu dodaj ga, ako jeste vrati true, ovo je najbolje
- U pythonu hashset se pravi sa set()
"""