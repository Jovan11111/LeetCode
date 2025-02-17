#include <vector>

class Solution {

public:


    int removeElement(std::vector<int> &nums, int val) {
        int cnt = 0;
        for (int i = 0; i < size(nums); i++) {
            if (nums[i] == val) nums[i] = -1;
            else cnt++;
        }
        int writeIdx = 0;
        for (int readIdx = 0; readIdx < size(nums); readIdx++) {
            if (nums[readIdx] != -1) {
                nums[writeIdx] = nums[readIdx];
                writeIdx++;
            }
        }
        return cnt;
    }
};