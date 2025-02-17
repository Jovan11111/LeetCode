# https://leetcode.com/problems/height-checker/description/
# Moje resenje
# Sortiram i izborjim, jako jednostavno, nema puno izmisljanja
# O(nlogn) O(n)
class Solution(object):
    def heightChecker(self, heights):
        expected = sorted(heights)
        counter = 0
        for i in range(len(heights)):
            if(heights[i] != expected[i]):
                counter += 1
        return counter
        

# Najbolje resenje
# Ovo resenje koristi count sort, i koristi se ako su vrednosti visina ogranicene (u ovom zadatku jesu)
# Recimo da su visine 1-100, onda je moguce uraditi ovakvo resenje
# O(n) O(n)
class Solution(object):
    def heightChecker(self, heights):
        # Pretpostavka: visine su između 1 i 100
        count = [0] * 101
        # Ide se kroz sve visine i broji se koliko koje visine ima. Npr ako 3 dece ima visinu 56, count[56] ce biti 3
        for h in heights:
            count[h] += 1

        index = 0
        mismatch = 0
        # Sada se ide redom za vrednosti 1-100. To ce zapravo biti sada prolazak redom kroz count. Posto niski ljudi imaju nizak indeks a visoki visok, onda ce ih ovaj niz sa indeksima zapravo sortirati
        for height in range(1, 101):
            # Znaci ako postoji neko sa tom visinom, i sve dok ima onih sa tom visinom
            while count[height] > 0:
                # Broji se koliko njih nije na pravom mestu. 
                if heights[index] != height:
                    mismatch += 1
                index += 1
                count[height] -= 1
        return mismatch
