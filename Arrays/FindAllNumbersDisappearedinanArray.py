# Potrebno naci brojeve 1-len(nums) koji se ne pojavljuju u nizu nums

# Moje resenje
# O(n), O(n). Nije lose al zauzima dodatni prostor
class Solution(object):
    def findDisappearedNumbers(self, nums):
        helper = []
        for i in range(len(nums)):
            helper.append(0)
        ret = []
        for i in range(len(nums)):
            helper[nums[i]-1] += 1
        for i in range(len(helper)):
            if(helper[i] == 0):
                ret.append(i+1)
        return ret

# Najbolje resenje:
# Ne zauzima dodatan prostor, O(n)
class Solution(object):
    def findDisappearedNumbers(self, nums):
        # Uzme se neki broj, npr nek je broj 5. Onda je index 4 (niz je 1-n, indeksi su 0-n-1)
        for num in nums:
            index = abs(num) - 1  # Pronalazimo odgovarajući indeks
            # Ako je broj na tom indeksu pozitivan, onda mu dati da je negativan. Tako to znaci da je broj nadjen. NADJEN je jer je broj koji je na indeksu vrednosti tog broja negativan
            if nums[index] > 0:
                nums[index] = -nums[index]  # Obeležavamo kao prisutan (negativan)
        # Oni koji us nadjeni u nizu, odgovarajuce vrenosti na njihovim indeksima su negativne, a oni koji nisu nadjeni, njihove vrednosti su pozitivne
        # Nama trebaju ove pozitivne
        # Brojevi na indeksima sa pozitivnim vrednostima nedostaju
        return [i + 1 for i in range(len(nums)) if nums[i] > 0]
