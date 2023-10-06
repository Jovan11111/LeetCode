#include <vector>

class Solution {
public:
    int integerBreak(int n) {
       std::vector<int> dp(n + 1);

        dp[0] = dp[1] = 0;

        for (int i = 2; i <= n; ++i) {
            int max_product = 0;
            for (int j = 1; j < i; ++j) {
                int product = std::max(j, dp[j]) * std::max(i - j, dp[i - j]);
                max_product = std::max(max_product, product);
            }
            dp[i] = max_product;
        }

        return dp[n];
    }
};
