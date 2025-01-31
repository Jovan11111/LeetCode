class Solution(object):
    def replaceElements(self, arr):
        cur_max = max(arr)
        for i in range(len(arr)-1):
            if arr[i] == cur_max:
                arr[i] = max(arr[i+1:len(arr)])
                cur_max = arr[i]
            else:
                arr[i] = cur_max
        arr[len(arr)-1] = -1
        return arr