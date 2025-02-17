#include "unordered_map"
#include "vector"
class Solution {
public:
    const int MOD = 1000000007;

    int rev(int x) {
        int ret = 0;
        while (x > 0) {
            int d = x % 10;
            ret = (10LL * ret + d) % MOD;
            x /= 10;
        }
        return ret;
    }

    int countNicePairs(std::vector<int>& nums) {
        std::vector<int> revs;
        int ret = 0;

        std::unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            revs.push_back(rev(nums[i]));
            int diff = (nums[i] - revs[i] + MOD) % MOD;
            ret = (ret + freq[diff]) % MOD;
            freq[diff] = (freq[diff] + 1) % MOD;
        }

        return ret;
    }
};
