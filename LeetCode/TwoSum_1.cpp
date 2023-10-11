#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> mapa;
        for(int i = 0; i < nums.size();i++){
            int comp = target - nums[i];
            if(mapa.find(comp) != mapa.end()){
                return{mapa[comp], i};
            }
            mapa[nums[i]] = i;
        }
        return {};
    }
};