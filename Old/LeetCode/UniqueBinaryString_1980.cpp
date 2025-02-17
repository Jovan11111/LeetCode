#include "string"
#include "bitset"
#include "vector"
#include "math.h"

class Solution {
public:
    std::string findDifferentBinaryString(std::vector<std::string>& nums) {

        for (int i = 0; i < pow(2, nums.size()); i++) {
            std::bitset<32> bin(i);
            if (std::find(nums.begin(), nums.end(), bin.to_string().substr(32 - nums.size())) == nums.end())
                return bin.to_string().substr(32 - nums.size());
        }
        return "";
    }
};
