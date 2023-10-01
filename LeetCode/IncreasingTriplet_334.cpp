#include <vector>
class Solution {
public:
    bool increasingTriplet(std::vector<int>& nums) {
        int i = INT_MAX;
        int j = INT_MAX;
        for(int q = 0; q < std::size(nums);q++){
            if(nums[q] <= i) i = nums[q];
            else if(nums[q] <= j) j = nums[q];
            else return true;
        }
        return false;
    }
};

