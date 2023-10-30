#include "vector"

class Solution {
public:
    int singleNonDuplicate(std::vector<int>& nums) {
        int i =0;
        while(i < nums.size()){
            if(i+1 == nums.size()) return nums[i];
            if(nums[i] != nums[i+1]) return nums[i];
            i+=2;
        }
        return 0;
    }
};