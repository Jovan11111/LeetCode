#include <vector>
class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums) {
        int min = INT_MAX;
        int sum = 0;
        int left = 0;
        for(int right = 0; right < std::size(nums);right++){
            sum+=nums[right];
            while(sum >= target){
                if(min > right-left+1) min = right-left+1;
                sum -= nums[left];
                left++;
            }
        }
        if(min == INT_MAX) return 0;
        else return min;
    }
};