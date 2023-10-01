#include <vector>
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        double sum = 0;
        double max = INT_MIN;
        for(int i = 0; i <k;i++) sum+=nums[i];
        max = sum/k;
        for(int i = k; i <std::size(nums);i++){
            sum += nums[i];
            sum -= nums[i-k];
            double avg = sum/k;
            if(avg > max) max = avg;
        }
        return max;
    }
};