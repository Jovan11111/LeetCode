#include <vector>
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if(nums[0] == 0){
            if(std::size(nums) != 1) return false;
            else return true;
        }
        for(int i = 0; i < std::size(nums);i++){
            for(int j = 0; j < nums[i]; j++){
                if(i+j<std::size(nums) && nums[i+j] == 0) nums[i+j] = -1;
            }
        }
        for(int i = 0; i < std::size(nums)-1;i++) if(nums[i] == 0) return false;
        return true;
    }
};