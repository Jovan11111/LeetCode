# https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/

# Moje resenje
# O(n2) O(1). Ne valja. Koristi se ovaj max, i to ne valja
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

# Najbolje resenje
# KORISTITI pristup problemu da se ide unazad. Krene se sdesna nalevo, i onda se cuva trenutni maksimum na koji smo naisli, i trenutnom elementu se da ta vrednost. Jako jednostavno resenje
# O(n) O(1)
class Solution(object):
    def replaceElements(self, arr):
        max_right = -1  # Početni maksimum desno (poslednji element treba da bude -1)
        
        for i in range(len(arr) - 1, -1, -1):  # Iteracija s desna na levo
            new_max = max_right               # Čuvamo prethodni maksimum
            max_right = max(max_right, arr[i])  # Ažuriramo maksimum ako je trenutni veći
            arr[i] = new_max                  # Zamenjujemo trenutni element sa prethodnim maksimumom

        return arr
