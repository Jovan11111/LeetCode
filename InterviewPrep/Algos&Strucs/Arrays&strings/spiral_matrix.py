# https://leetcode.com/problems/spiral-matrix/
# Moje resenje
# Optimalno, O(mxn), O(1)
class Solution(object):
    def spiralOrder(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        ret = []
        s1 = 0
        s2 = n
        s3 = m
        s4 = 0
        while(True):
            for i in range(s4, s2):
                ret.append(matrix[s1][i])
            s1 += 1
            for i in range(s1, s3):
                ret.append(matrix[i][s2-1])
            s2 -=  1
            if(s3 <= s1 or s2 <= s4):
                break
            for i in range(s2-1, s4-1, -1):
                ret.append(matrix[s3-1][i])
            s3 -= 1
            for i in range(s3-1, s1-1, -1):
                ret.append(matrix[i][s4])
            s4 += 1
            if(s3 <= s1 or s2 <= s4):
                break
        return ret
