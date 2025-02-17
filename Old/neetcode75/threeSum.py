class Solution:
    def threeSum1(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        if len(nums) == 3:
            return [] if sum(nums) != 0 else [nums]

        ret = []
        for i in range(len(nums)-2):
            for j in range(i+1, len(nums)-1):
                for k in range(j+1, len(nums)):
                    if nums[i] + nums[j] + nums[k] == 0:
                        if(sorted([nums[i], nums[j], nums[k]]) not in ret):
                            ret.append(sorted([nums[i], nums[j], nums[k]]))
        return ret

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ret = []
        n = len(nums)
        
        for a in range(n - 2):
            if a > 0 and nums[a] == nums[a - 1]:
                continue
            b, c = a + 1, n - 1
            while b < c:
                total = nums[a] + nums[b] + nums[c]
                if total < 0:
                    b += 1
                elif total > 0:
                    c -= 1
                else:
                    ret.append([nums[a], nums[b], nums[c]])
                    while b < c and nums[b] == nums[b + 1]:
                        b += 1
                    while b < c and nums[c] == nums[c - 1]:
                        c -= 1
                    b += 1
                    c -= 1

        return ret
"""
- Moje resenje
- Seljacko, samo ide kroz sve elemente i proevrava da li je to to, ne valja
- vremenski O(n^3)
- Pravilno resenje:
- Prvo se sortira niz, ovo je dobro za skidanje duplikata, na istu poziciju isti broj moze samo jednom
- KAd je sortirano i kad je prvi element pozitivan, to je to prekida se
- Kad je sortirano, izabere se prvi element, i onda se radi twosum za trazenje ostalih
- Ovako je resenje O(n^2), jebiga to je jedini nacin
"""
