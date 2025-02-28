# https://leetcode.com/problems/merge-sorted-array/
# Moje resenje
# O(m + n) O(m + n). Nije lose resenje, ali moze bolje. Zauzima se dodatan prostor iako ne bi trebalo
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

# Najbolje resenje
# Slicno kao i dupliranje nula, isto se ide unazad i procenjuje se dokle ce ici taj niz
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        p1 = m - 1          # Pokazivač na poslednji validni element u nums1
        p2 = n - 1          # Pokazivač na poslednji element u nums2
        p = m + n - 1       # Pokazivač na poslednju poziciju u nums1 (on ima one dodatne nule)

        # Ide se unazad dok su oni veci od nule, i uzima se veci i stavlja se na kraj. Onda se dodaje i dodaje i eto
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            p -= 1
        # Dodaju se elementi koji su preostali. Ne mora da se radi za nums1, jer su oni vec na mestu, u njih se ubacuju ovi iz nums2
        # Ako su preostali elementi u nums2 (nums1 su već na mestu)
        while p2 >= 0:
            nums1[p] = nums2[p2]
            p2 -= 1
            p -= 1
