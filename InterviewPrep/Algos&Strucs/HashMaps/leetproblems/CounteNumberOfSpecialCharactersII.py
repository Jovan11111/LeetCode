# https://leetcode.com/problems/count-the-number-of-special-characters-ii/

class Solution(object):
    def numberOfSpecialChars(self, word):
        """
        :type word: str
        :rtype: int
        """
        SMALL_OCCURED = 1
        BIG_OCCURED = 2
        CANCELED = 0
        hashMap = dict()
        
        for letter in word:
            if letter.islower():
                if letter in hashMap:
                    if hashMap[letter] == BIG_OCCURED:
                        hashMap[letter] = CANCELED
                else:
                    hashMap[letter] = SMALL_OCCURED
            else:
                if letter.lower() in hashMap:
                    if hashMap[letter.lower()] == SMALL_OCCURED:
                        hashMap[letter.lower()] = BIG_OCCURED
                else:
                    hashMap[letter.lower()] = CANCELED
        
        counter = 0
        for _, v in hashMap.items():
            if v == BIG_OCCURED:
                counter += 1
        
        return counter
        
        
