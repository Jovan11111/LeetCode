#include<vector>

class Solution {
public:
    int maxDotProduct(std::vector<int> &nums1, std::vector<int> &nums2) {

        std::vector<std::vector<long long>> dp(nums1.size() + 1, std::vector<long long>(nums2.size() + 1, INT_MIN + 1));

        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                long long cp = static_cast<long long>(nums1[i - 1]) * nums2[j - 1];

                dp[i][j] = std::max({
                                            dp[i - 1][j - 1] + cp,
                                            dp[i - 1][j],
                                            dp[i][j - 1],
                                            cp
                                    });
            }
        }
        return dp[nums1.size()][nums2.size()];
    }
};