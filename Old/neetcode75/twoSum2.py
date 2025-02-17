class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers) - 1

        while numbers[left] + numbers[right] != target:
            if numbers[left] + numbers[right] < target:
                left += 1
            
            if numbers[left] + numbers[right] > target:
                right -= 1

        return [left + 1, right + 1]

"""
- Moje resenje:
- Posto je niz sortiran, krene se sleva i sdesna, i ako je zbir manji potrebno je povecati ga, pomeriti levi pokazivac napred
- A ako je zbir prevelik, potrebno je smanjiti ga, pomeriti desni pokazivac nazad
- Pravilno resenje isto
"""
