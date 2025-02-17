class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = []
        mapa = {}

        for word in strs:
            if ''.join(sorted(word)) in mapa:
                mapa[''.join(sorted(word))].append(word)
            else:
                mapa[''.join(sorted(word))] = [word]

        return [v for k, v in mapa.items()]