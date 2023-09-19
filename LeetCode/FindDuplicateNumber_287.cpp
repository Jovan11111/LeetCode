#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        std::vector<int> ttt (std::size(nums));
        for(int num:nums){
            if(ttt[num-1] == 1) return num;
            else ttt[num-1] = 1;
        }
        return 0;
    }
};