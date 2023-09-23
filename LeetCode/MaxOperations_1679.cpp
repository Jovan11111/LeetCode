#include <vector>
#include <unordered_map>

class Solution {
public:
    int maxOperations(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map;
        int operations = 0;

        for (int num : nums) {
            int complement = k - num;
            if (freq_map[complement] > 0) {
                operations++;
                freq_map[complement]--;
            } else {
                freq_map[num]++;
            }
        }

        return operations;
    }
};