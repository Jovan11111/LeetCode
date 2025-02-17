#include "vector"
#include "unordered_map"

class Solution {
public:
    int minPairSum(std::vector<int>& nums) {
        std::unordered_map<int, int> mapa;
        int max = *std::max_element(nums.begin(), nums.end());
        int min = *std::min_element(nums.begin(), nums.end());

        for(int i = 0; i < nums.size();i++) mapa[nums[i]]++;

        int ret = INT_MIN;
        while (min <= max) {
            if (mapa[min] == 0) min++;
            else if (mapa[max] == 0) max--;
            else {
                ret = ret > min+max ? ret : min+max;
                mapa[min]--;
                mapa[max]--;
            }
        }

        return ret;
    }
};