#include "string"

class Solution {
    int mod = 1000000007;
public:
    int countHomogenous(std::string s) {
        long cnt = 1;
        int ret = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] != s[i + 1]) {
                ret += ((cnt * (cnt + 1)) % mod) / 2; // zbir brojeva od 1 do cnt, koliko ima istih
                cnt = 1;
            } else cnt++;
        }
        ret += ((cnt * (cnt + 1)) % mod) / 2;
        return ret % mod;
    }
};