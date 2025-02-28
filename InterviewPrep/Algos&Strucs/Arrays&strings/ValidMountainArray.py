class Solution(object):
    def validMountainArray(self, arr):
        
        if len(arr) < 3:
            return False
        
        decreasing = False
        
        for i in range(len(arr) - 1):
            if decreasing:
                if arr[i] > arr[i+1]:
                    continue
                else:
                    return False
            else:
                if arr[i] < arr[i+1]:
                    continue
                elif arr[i] == arr[i+1]:
                    return False
                else:
                    if i != 0:
                        decreasing = True
                    else:
                        return False
        return decreasing        