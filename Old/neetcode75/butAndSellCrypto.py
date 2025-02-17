class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buyDay, sellDay = 0, 1
        maks = 0

        while sellDay != len(prices):
            if prices[buyDay] > prices[sellDay]:
                buyDay, sellDay = sellDay, sellDay+1;
            else:
                maks = max(maks, prices[sellDay] - prices[buyDay])
                sellDay += 1
        return maks

"""
- Moje resnje: 
- gledaju se dan zaprodaju i dan za kupovinu. Dan za kupovinu uvek treba da pokazuje da najnizu cenu na koju smo do sada naisli, a 
dan za prodaju ide od tog i gleda koji je maksimum. Jednostavno resenje
- Njihovo resnje:
- Slicno, ali ista slozenost
"""