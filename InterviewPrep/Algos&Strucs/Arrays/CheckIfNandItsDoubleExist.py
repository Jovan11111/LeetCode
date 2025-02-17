# U nizu se trazi da li postoje i, j tako da arr[i] == arr[j].
# Moje resenje
# O(nlogn), O(1)
class Solution(object):
    def checkIfExist(self, arr):
        # Prvo sortiram, O(logN)
        arr = sorted(arr)
        i = 0
        j = 1
        # Koristim 2 pokazivaca da obidjem elemente, pokazivaci su i i j
        while(j < len(arr) and i < len(arr)):
            if arr[i] * 2 == arr[j] or arr[i] / 2 == arr[j]:
                if(i != j):
                    return True
                else:
                    j += 1
            elif arr[i]*2 > arr[j]:
                # Ako je j premali, on se pomera napred. Niz je soritran znaci sledeci j ce biti veci
                j += 1
            else:
                # Ako je i premali, onda se on pomera
                i += 1
        return False

# Bolje resenje
# O(n), O(n)
class Solution(object):
    def checkIfExist(self, arr):
        # Koristi se set. Ovo je zapravo HashSet. set struktura u pajtonu je napravljena tako da joj je dohvatanje elemenata O(1)
        seen = set()
        for num in arr:
            # Za svaki broj se proverava da li je njegova dupla vrednost u elementima koji su prosli. Ako jeste, onda je zadatak treba da vrati True
            # Takodje, posto ovde niz nije sortiran, mora se proveravati i da li je polovina tog broja u brojevima koji su prosli. ako jeste zadatak isto treba da vrati True
            if 2 * num in seen or (num % 2 == 0 and num // 2 in seen): # num in set slozenost je O(1) A NE O(n)
                return True
            # Ako broj num ne ispunjava uslov zadatka, onda se on dodaje u HashSet, i ide se dalje
            seen.add(num)
        return False
