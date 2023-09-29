#include <vector>
class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        int smer = 0;
        int j = 0;
        while(j < std::size(nums)-1 && nums[j] == nums[j+1]) j++;
        if(j == std::size(nums)-1) return true;
        if(nums[j] >= nums[j+1]) smer = 1;
        for(int i = 0; i <std::size(nums)-1;i++){
            if(smer == 0){
                if(nums[i] > nums[i+1]) return false;
            }
            else{
                if(nums[i] < nums[i+1]) return false;
            }
        }
        return true;
    }
};