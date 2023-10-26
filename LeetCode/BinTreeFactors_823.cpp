#include <vector>
#include <unordered_map>

class Solution {
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        std::unordered_map<int, long long> dp;

        for (int i = 0; i < arr.size(); i++) {
            dp[arr[i]] = 1;

            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int x = arr[i] / arr[j];
                    if (dp.count(x)) {
                        // If the factor exists in the map, update the count
                        dp[arr[i]] = (dp[arr[i]] + dp[arr[j]] * dp[x]) % 1000000007;
                    }
                }
            }
        }

        int ret = 0;
        for (auto& entry : dp) {
            ret = (ret + entry.second) % 1000000007;
        }

        return ret;
    }
};
