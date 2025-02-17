#include <vector>
class Solution {
public:
    int maximumScore(std::vector<int>& nums, int k) {
        int l = k;
        int r = k;
        int min = nums[k];
        int max = min;

        while (l > 0 || r < nums.size() - 1) {
            if (l == 0 || (r < nums.size() - 1 && nums[r + 1] > nums[l - 1])) r++;
            else l--;

            int x = nums[l] < nums[r] ? nums[l] : nums[r];
            min = min < x ? min : x;
            max = max < min * (r-l+1) ? min*(r-l+1) : max;
        }

        return max;
    }
};