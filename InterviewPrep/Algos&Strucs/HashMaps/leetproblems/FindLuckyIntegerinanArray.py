# https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution(object):
    def findLucky(self, arr):
        ret = -1
        mapa = dict()
        for el in arr:
            if el in mapa:
                mapa[el] += 1
            else:
                mapa[el] = 1
        
        for k, v in mapa.items():
            if k == v:
                ret = max(ret, k)
        return ret
