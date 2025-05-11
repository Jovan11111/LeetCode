# https://leetcode.com/problems/longest-string-chain/description/

class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        hashMap = dict()
        words.sort(key = lambda x: len(x))
        for word in words:
            for i in range(len(word)):
                potential_pred = word[:i] + word[i+1:]
                if potential_pred in hashMap:
                    if word in hashMap:
                        hashMap[word] = max(hashMap[word], hashMap[potential_pred]  + 1)
                    else:
                        hashMap[word] = hashMap[potential_pred]  + 1

                else:
                    if not word in hashMap:
                        hashMap[word] = 1
        return max(hashMap.values())


        
        
