# Naci brojeve koji imaju paran broj elemenata

# Moje resenje
# O(n), O(1). Resenje je tacno za uslove zadatka (pise brojevi 1-100000). 
# Ako bi neko pitao kako sad ovo prosiriti za sve brojeve, onda mora da se menja zadatak
class Solution(object):    
    def findNumbers(self, nums):
        ret = 0
        for el in nums:
            if((el > 9 and el < 100) or (el > 999 and el < 10000) or (el > 99999)):
                ret += 1
        return ret

# Najbolje resenje
# PRISTI se log10 kako se koristi
# 1-9 imaju log10<1
# 10-99 imaju 2>log10>1
# 100-999 imaju 3>log10>2
# itd. Znaci ako je log10 neparan onda broj ima paran broj cifara. Pametno resenje
# O(n) O(1)
# Ako ti se ovo resenje ne svidja, uvek moze da se radi len(str(arr[i])) % 2. To je seljacko resenje, i ima vremenski O(n*d) gde je d prosecan broj cifara
import math

class Solution(object):
    def findNumbers(self, nums):
        ret = 0
        for el in nums:
            if int(math.log10(el)) % 2 == 1:  # log10(12) ≈ 1.08 -> 1 + 1 = 2 cifre
                ret += 1
        return ret
