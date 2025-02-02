# https://leetcode.com/problems/remove-duplicates-from-sorted-array/
# Moje resenje
# O(n) O(n). Moze bolje, da se ne koristi dodatni prostor
class Solution(object):
    def removeDuplicates(self, nums):
        helper = set()
        for el in nums:
            helper.add(el)
        for i, el in enumerate(helper):
            nums[i] = el
        return len(helper)

# Bolje resenje
# Koristi se 2 pointer gde ce biti jedan pointer koji ce gledati gde je poslednji jedinstven element, i onda jedan koji ide napred i gleda dokle ima istih elemenata
# Znaci ako je niz npr 12333345, i ce pokazivati na prvu trojku, a j ce ici i gledati koliko ih ima napred
class Solution(object):
    def removeDuplicates(self, nums):
        # Ako nums ne postoji
        if not nums:
            return 0
        i = 0  # Pokazivač na poslednji jedinstveni element
        for j in range(1, len(nums)):
            if nums[j] != nums[i]:  # Nađen novi jedinstveni element. Ovo moze da se radi posto je niz sortiran, znaci da ce svi duplikati biti jedni pored drugih
                i += 1
                nums[i] = nums[j]   # Upisujemo jedinstveni element
        return i + 1  # Broj jedinstvenih elemenata
