#include "vector"

class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
        std::vector<std::vector<int>> vals;
        std::vector<int> ret;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                vals.push_back({i + j, i, nums[i][j]});
            }
        }

        std::sort(vals.begin(), vals.end(), [](const auto& a, const auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            else
                return a[0] < b[0];
        });

        for (const auto& v : vals) {
            ret.push_back(v[2]);
        }

        return ret;
    }
};
