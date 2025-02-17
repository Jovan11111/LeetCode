class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapa = {el: target-el for el in nums}
        
        for k, v in mapa.items():
            if k in mapa.values() and v in mapa.keys():
                if k == v and nums.count(k) == 1:
                    continue
                if k == v:
                    passed = False
                    save = 0
                    for i in range(len(nums)):
                        if nums[i] == k:
                            if passed == True:
                                save = i
                                break
                            else:
                                passed = True
                    return [list(mapa.keys()).index(k), save]    
                return [list(mapa.keys()).index(k), list(mapa.keys()).index(v)]
"""
Pravilno resenje:
- Svako sa svakim, bezveze resenje, O(n2)
- Napravi se hessmapa kojoj su kljucevi vrednsoti niza, a vrednosti su indeksi niza
- Ide se kroz niz, i proverava se da li se razlika trenutnog elemena i targeta nalazi u mapi, ako se nalazi to se vraca
- Ako se ne nalazi, onda se doda element i njegov indeks u mapu
Kod:

mapa = dict()

for el, i in enumerate(nums):
    if target-el in mapa:
        return [mapa[target-el], i]
    mapa[el] = i
"""