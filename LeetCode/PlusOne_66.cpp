#include "vector"

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        for(int i = digits.size()-1; i >= 0; i--){
            digits[i]++;
            if(digits[i] < 10) break;
        }
        if(digits[0] == 10){
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        for(int i = 0; i <digits.size();i++)if(digits[i] == 10) digits[i] = 0;
        return digits;
    }
};