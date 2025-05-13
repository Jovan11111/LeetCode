 # https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/

class Solution(object):
    def removeTrailingZeros(self, num):
        """
        :type num: str
        :rtype: str
        """
        endOfString = len(num) - 1
        while(num[endOfString] == '0'):
            endOfString -= 1
        
        return num[:endOfString+1]
