#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        int ret = nums[0];
        int cnt = 1;
        for (int i = 1; i < std::size(nums); i++) {
            if(cnt == 0){
                ret = nums[i];
                cnt = 1;
            }
            else if(nums[i] == ret) cnt++;
            else cnt--;
        }
        return ret;
    }
};