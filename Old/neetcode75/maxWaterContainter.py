class Solution:
    def maxArea1(self, heights: List[int]) -> int:
        maks = 0
        for i in range(len(heights) - 1):
            for j in range(i + 1, len(heights)):
                area = min(heights[i], heights[j]) * (j - i)
                maks =  area if maks < area else maks

        return maks

    def maxArea(self, heights: List[int]) -> int:
        left = 0
        right = len(heights) - 1
        ret = []
        while left < right:
            ret.append(min(heights[left], heights[right]) * (right - left))
            if heights[left] > heights[right]:
                right -= 1
            else:
                left += 1

        return max(ret)

"""
- Moje prvo resenje:
- Seljacko resenje, prodje se kroz sve elemente i odredi se maks, najjednostavnije ali O(n^2), moze bolje
- Moje drugo resenje:
- Krene se od pocetka i od kraja, u neki niz se ubaci vrednost vode koja moze da stane izmedju pocetka i kraja. Onda se gleda koji je pillar manji
- ako je levi manji, levi pointer se pomera, ako je desni manji onda se desni pomera, i tako dok se ne spoje. Onda su provereni svi vazni slucajevi i uzme se maks iz toga niza
- Pravilno resenje:
- Ne treba niz vec samo jedna verijabla u koju se upisuju vrednosti, al logika ista
"""