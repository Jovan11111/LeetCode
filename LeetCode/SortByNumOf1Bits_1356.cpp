#include "vector"

class Solution {
public:
    std::vector<int> sortByBits(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), sortAlg);
        return arr;

    }

    static bool sortAlg(int a, int b){
        if(__builtin_popcount(a) == __builtin_popcount(b)) return a<b;
        else return __builtin_popcount(a) < __builtin_popcount(b);
    }
};