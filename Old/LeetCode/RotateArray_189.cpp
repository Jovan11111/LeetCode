#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k %= size(nums);
        std::vector<int> rotated( size(nums));

        for (int i = 0; i < size(nums); i++) {
            rotated[(i + k) % size(nums)] = nums[i];
        }

        nums = rotated;

    }
};