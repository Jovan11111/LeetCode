class Solution(object):
    def duplicateZeros(self, arr):
        helper = []
        for el in arr:
            if el == 0:
                helper.append(0)
                helper.append(0)
            else:
                helper.append(el)
        for i in range(len(arr)):
            arr[i] = helper[i]
        