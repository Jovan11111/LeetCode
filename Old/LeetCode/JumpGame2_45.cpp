#include <vector>
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int help = 0;
        int ret = 0;
        int temp = 0;
        for(int i = 0; i < std::size(nums)-1; i++){
            help = help > i + nums[i] ? help : i + nums[i];
            if(i == temp){
                temp = help;
                ret++;
            }
        }
        return ret;
    }
};