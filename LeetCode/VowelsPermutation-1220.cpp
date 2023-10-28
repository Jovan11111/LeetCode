#include <vector>

class Solution {
public:
    int countVowelPermutation(int n) {
        std::vector<long> dp0(k, 1);
        std::vector<long> dp1(k);

        for (int j = 2; j <= n; j++) {
            dp1[a] = (dp0[e] + dp0[i] + dp0[u]) % 1000000007;
            dp1[e] = (dp0[a] + dp0[i]) % 1000000007;
            dp1[i] = (dp0[e] + dp0[o]) % 1000000007;
            dp1[o] = dp0[i];
            dp1[u] = (dp0[i] + dp0[o]) % 1000000007;
            std::swap(dp0, dp1);
        }

        return (dp0[a] + dp0[e] + dp0[i] + dp0[o] + dp0[u]) % 1000000007;
    }
private:
    enum vowel {
        a,
        e,
        i,
        o,
        u,
        k,
    };
};