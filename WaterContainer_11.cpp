#include <vector>

class Solution {
public:
    int maxArea(std::vector<int> &height) {
        int left = 0;
        int maxWater = 0;
        int right = std::size(height) - 1;

        while (left < right) {
            maxWater = std::max(maxWater, std::min(height[left], height[right]) * (right - left));
            if (height[left] < height[right]) left++;
            else right--;
        }

        return maxWater;
    }
};