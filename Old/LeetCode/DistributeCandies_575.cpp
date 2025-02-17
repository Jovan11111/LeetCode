#include "vector"

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        int n = candyType.size();
        int k = n / 2;
        int ret = 1;
        std::sort(candyType.begin(), candyType.end());
        for(int i = 0; i < n-1 && k > 1 ; i++){
            if(candyType[i] != candyType[i+1]) {k--;ret++;}
        }
        return ret;
    }
};