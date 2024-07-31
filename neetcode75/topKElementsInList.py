class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mapa = {}
        ret = []
        for num in nums:
            if num in mapa:
                mapa[num] += 1
            else:
                mapa[num] = 1
        
        return [key for key, v in mapa.items() if v >= sorted(list(mapa.values()), reverse = True)[k-1]]
