#include <vector>
class Solution {
public:
    int numWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        int maxPosition = std::min(arrLen - 1, steps / 2);
        std::vector<std::vector<int>> dp(steps + 1, std::vector<int>(maxPosition + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j <= maxPosition; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                }
                if (j < maxPosition) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
                }
            }
        }

        return dp[steps][0];
    }
};