#include <vector>
class Solution {
public:
    int numOfArrays(int n, int m, int k) {

        std::vector<std::vector<int>> prvi(m+1, std::vector<int>(k+1, 0));
        std::vector<std::vector<int>> prefix(m+1, std::vector<int>(k+1, 0));
        std::vector<std::vector<int>> prevDp(m+1, std::vector<int>(k+1, 0));
        std::vector<std::vector<int>> prevPrefix(m+1, std::vector<int>(k+1, 0));

        for (int j = 1; j <= m; j++) {
            prevDp[j][1] = 1;
            prevPrefix[j][1] = j;
        }

        for (int _ = 2; _ <= n; _++) {
            prvi.assign(m+1, std::vector<int>(k+1, 0));
            prefix.assign(m+1, std::vector<int>(k+1, 0));

            for (int maxNum = 1; maxNum <= m; maxNum++) {
                for (int cost = 1; cost <= k; cost++) {
                    prvi[maxNum][cost] = (static_cast<long long>(maxNum) * prevDp[maxNum][cost]) % 1000000007;

                    if (maxNum > 1 && cost > 1) {
                        prvi[maxNum][cost] = (prvi[maxNum][cost] + prevPrefix[maxNum - 1][cost - 1]) % 1000000007;
                    }

                    prefix[maxNum][cost] = (prefix[maxNum - 1][cost] + prvi[maxNum][cost]) % 1000000007;
                }
            }

            prevDp = prvi;
            prevPrefix = prefix;
        }

        return prefix[m][k];
    }
};