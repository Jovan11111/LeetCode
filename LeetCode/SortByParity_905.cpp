#include <vector>
class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums) {
        int i = 0;
        int j = std::size(nums)-1;
        while(i != j){
            if(nums[i] % 2 == 0){i++; continue;}
            if(nums[j] % 2 == 1){j--; continue;}
            int t = nums[i];
            nums[i] = nums[j];
            nums[j] = t;
        }
        return nums;
    }
};