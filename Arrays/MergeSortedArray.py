class Solution(object):
    def merge(self, nums1, m, nums2, n):
        p1 = 0
        p2 = 0
        helper = []
        while(p1 < m and p2 < n):
            if nums1[p1] < nums2[p2]:
                helper.append(nums1[p1])
                p1 += 1
            else:
                helper.append(nums2[p2])
                p2 += 1
        if p1 == m:
            for i in range(p2, n):
                helper.append(nums2[i])
        else:
            for i in range(p1, m):
                helper.append(nums1[i])
        for i in range(len(helper)):
            nums1[i] = helper[i]