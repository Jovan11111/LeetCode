# Potrebno svaku nulu u nizu duplirati

# Moje resenje:
# O(n), O(n). Sve super al moze da prostorna bude O(1). 
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

# Najbolje resenje:
# Resenje radi inplace, i radi O(n), znaci da ne zauzima dodatni prostor.
class Solution(object):
    def duplicateZeros(self, arr):
        n = len(arr) # Cuva se duzina originalnog niza
        zeros = arr.count(0)  # Broj nula koje treba duplirati
        i = n - 1 # i je pokazivac koji pokazuje na poslednji element u trenutnom nizu
        j = n + zeros - 1  # j pokazuje na poslednji element u nizu kada on bude promenjen

        # Ovaj uslov za j < n obezbedjuje da niz ostane iste velicine, to zapravo znaci da ono sto je visak da ce biti samo izbaceno
        # Pomeranje unazad
        while i < j:
            if j < n: # Sada kada je j < n moze da krene kopiranje na prava mesta
                arr[j] = arr[i]  # Kopiraj element na pravo mesto
            # Kad se naidje na nulu u originalnom nizu, potrebno je pomeriti j za jedan, i onda dodati tu nulu ako je j < n
            if arr[i] == 0:
                j -= 1
                if j < n:
                    arr[j] = 0  # Dupliraj nulu
            # Smanji obojicu
            i -= 1
            j -= 1

        
