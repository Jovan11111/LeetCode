#include <string>
class Solution {
public:
    std::string decodeAtIndex(std::string s, int k) {
        long long size = 0;
        std::string ret = "";
        for (char c : s) {
            if (isalpha(c)) {
                size++;
            } else {
                size *= c - '0';
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            k %= size;
            if (k == 0 && isalpha(s[i])) {
                ret +=s[i];
                return ret;
            }

            if (isalpha(s[i])) {
                size--;
            } else {
                size /= s[i] - '0';
            }
        }

        return " ";
    }
};