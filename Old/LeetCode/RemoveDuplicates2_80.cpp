#include <vector>

class Solution {
public:

    int removeDuplicates(std::vector<int> &nums) {
        int cnt = 0;
        for (int i = 0; i < size(nums); i++) {
            if (i != size(nums) - 1 && i != size(nums) - 2 && nums[i] == nums[i + 1] &&
                nums[i] == nums[i + 2]) { nums[i] = -999; }
            else cnt++;
        }
        int writeIdx = 0;
        for (int readIdx = 0; readIdx < size(nums); readIdx++) {
            if (nums[readIdx] != -999) {
                nums[writeIdx] = nums[readIdx];
                writeIdx++;
            }
        }
        return cnt;
    }
};
