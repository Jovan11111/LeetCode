#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int maxPrice = 0;
        int min = prices[0];
        for(int i = 1; i <std::size(prices);i++){
            if(prices[i]<min) min = prices[i];
            else{
                int cur = prices[i] - min;
                if(cur >maxPrice) maxPrice = cur;
            }
        }
        return maxPrice;
    }
};

