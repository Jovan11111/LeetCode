class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0

        helper = sorted(nums)
        
        ret = 0
        cnt = 1

        for i in range(1, len(helper)):
            if helper[i] - helper[i-1] > 1:
                ret = ret if ret > cnt else cnt
                cnt = 1
                
            elif helper[i] != helper[i-1]:
                cnt += 1
        
        return cnt if ret < cnt else ret;

    def longestConsecutivebolje(self, nums: List[int]) -> int:
        nums = set(nums)
        
        cnt = 0
        ret = 0

        for el in nums:
            if not el-1 in nums:
                cnt = 1
                while(el+cnt) in nums:
                    cnt +=1
                ret = ret if ret > cnt else cnt
        return ret
# - Moje resenje: Sortiraj i idi kroz niz
# - Bolje resenje:
# - array se prevede u set, sad je lakse
# - Proverava se za svaki broj da li ima levog komsiju na number line, ako nema onda je on pocetak neke sekvence
# - Ako je pocetak neke sevence, trazi se desni komsija, ako postoji to znaci da se sekvenca nastavlja
# - To se radi dok se ne dodje do kraja usput se broji sekvence i to je to.
# - Kada se dodje do kraja sekvence, prelazi se na sledeci element i onda se to radi opet, proverava se postoji li levi komsija itd

