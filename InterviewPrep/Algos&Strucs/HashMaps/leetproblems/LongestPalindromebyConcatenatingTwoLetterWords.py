# https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

class Solution(object):
    def longestPalindrome(self, words):
        same_hash = dict()
        diff_hash = dict()
        ret = 0
        same_exist = False
        odd_number = False
        for word in words:
            if word[0] == word[1]:
                same_exist = True
                if word in same_hash:
                    same_hash[word] += 1
                else:
                    same_hash[word] = 1
            else:
                if word[::-1] in diff_hash:
                    ret += 4
                    if diff_hash[word[::-1]] > 0:
                        diff_hash[word[::-1]] -= 1
                    else:
                        del diff_hash[word[::-1]]
                else:
                    if word in diff_hash:
                        diff_hash[word] += 1
                    else:
                        diff_hash[word] = 0

        for k, v in same_hash.items():
            ret += int(v / 2) * 4
            if v % 2:
                odd_number = True
        if same_exist and odd_number:
            ret += 2
        return ret
