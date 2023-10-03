#include <vector>
class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < std::size(nums);i++){
            for(int j = i+1; j <std::size(nums);j++){
                if(nums[i] == nums[j]) cnt++;
            }
        }
        return cnt;
    }
};