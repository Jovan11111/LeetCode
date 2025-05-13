# https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/

class Solution(object):
    def removeAnagrams(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """

        def areAnagrams(word1, word2):
            return ''.join(sorted(word1)) == ''.join(sorted(word2))

        i = 0 
        while i < len(words) - 1:
            if areAnagrams(words[i], words[i+1]):
                words.pop(i+1)
            else:
                i += 1
        
        return words
