#include <vector>
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int ret = 0;
        for(int i = 1; i < std::size(prices);i++){
            if(prices[i] > prices[i-1]) ret += prices[i] - prices[i-1];
        }
        return ret;
    }
};