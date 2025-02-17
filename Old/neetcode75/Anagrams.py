class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False

        mapa1 = dict()

        for ch in s:
            if ch in mapa1:
                mapa1[ch] += 1
            else:
                mapa1[ch] = 1
        
        for ch in t:
            if ch not in mapa1:
                return False
            else:
                mapa1[ch] -= 1
        
        if list(mapa1.values()).count(0) == len(mapa1):
            return True
        return False

"""
Resenja:
- Izbrojis koliko cega ima i ubacis u hes mapu, stavis u razlicite hes mape jednu i drugu rec i onda uporedis hes mape
- O(n) vremenski
- Sortiranje, soritras stringove i uporedis ih i to je to, sporije al zauzima manje memorije

"""