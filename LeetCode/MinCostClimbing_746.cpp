#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        int n = cost.size();
        std::vector<int> mins(n + 1);
        mins[0] = 0;
        mins[1] = 0;

        for (int i = 2; i <= n; i++) {
            mins[i] = std::min(mins[i - 1] + cost[i - 1], mins[i - 2] + cost[i - 2]);
        }

        return mins[n];
    }
};

