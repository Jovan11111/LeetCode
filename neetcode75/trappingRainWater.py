class Solution:
    def trapMy(self, height: List[int]) -> int:
        ret = []
        for i in range(1, len(height)-1):            
            leftMax = max(height[0:i])
            rightMax = max(height[i+1:len(height)])
            numWater = min(leftMax, rightMax) - height[i]

            ret.append(numWater if numWater > 0 else 0)
        return sum(ret)

    def trapOneLine(self, height: List[int]) -> int:   
        return sum([min(max(height[0:i]), max(height[i+1:len(height)])) - height[i] if min(max(height[0:i]), max(height[i+1:len(height)])) - height[i] > 0 else 0 for i in range(1, len(height)-1)])

    def trap(self, height: List[int]) -> int:
        zbir = 0
        left, right = 0, len(height) - 1
        leftMax, rightMax = height[left], height[right]

        while(left < right):
            if leftMax < rightMax:
                left += 1
                zbir += leftMax - height[left] if leftMax - height[left] > 0 else 0
                leftMax = max(leftMax, height[left])

            else:
                right -= 1
                zbir += rightMax - height[right] if rightMax - height[right] > 0 else 0
                rightMax = max(rightMax, height[right])

        return zbir
"""
Moje resenje:
- Nisam nasao
- Pravilno resenje  1:
- Ide se kroz sve visine, i nadje se najvisi pillar sa leve strane i najvisi pillar sa desne strane. 
- Voda koja moze da stane je onoliko koliko je visok nizi od ta dva pillara, i oduzme s ekoliko je visok onaj pillar koji sad posmatramo
- Jednostavno, ali nije bas dobro resenje, prolazi se jednom kroz niz ali se traze max cesto, recimo O(n^2)
- Pravilno resenje 2:
- 2 pointera, levi i desni na pocetak i na kraj. 2 promenljive, max left i max rigth koje pokazuju dosadasnju najvecu visinu
- Ide se dok se dva pointera ne susretnu, i to tako sto se gleda da li je dosadanja najveca visina manja sa leve ili sa desne strane. Nije nas briga sto npr sa druge strane mozda ima i vecih visina,
- jer se svakako uzima min visina a to je sigurno ona koju smo izabrali. pokazivac na levo se pomeri, doda se na zbir i promeni se max ako je potrebno
"""