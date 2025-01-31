class Solution(object):
    def checkIfExist(self, arr):
        arr = sorted(arr)
        i = 0
        j = 1
        while(j < len(arr) and i < len(arr)):
            if arr[i] * 2 == arr[j] or arr[i] / 2 == arr[j]:
                if(i != j):
                    return True
                else:
                    j += 1
            elif arr[i]*2 > arr[j]:
                j += 1
            else:
                i += 1
        return False