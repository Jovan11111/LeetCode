#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        std::string m = "";
        for (int i = 0; i < std::size(s); i++) {
            int l = i;
            int r = i;
            while (l >= 0 && r < std::size(s) && s[l] == s[r]) {
                l--;
                r++;
            }
            l++;
            r--;
            if (r - l + 1 > std::size(m)) {
                m = s.substr(l, r - l + 1);
            }

            l = i;
            r = i + 1;
            while (l >= 0 && r < std::size(s) && s[l] == s[r]) {
                l--;
                r++;
            }
            l++;
            r--;
            if (r - l + 1 > std::size(m)) {
                m = s.substr(l, r - l + 1);
            }
        }
        return m;
    }
};
