#include <string>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::string ret = "";
        std::string help = "";
        for (int i = 0; i < std::size(s); i++) {
            if (s[i] == ' ') {
                for (int j = std::size(help) - 1; j >= 0; j--) {
                    ret += help[j];
                }
                ret += ' ';
                help = "";
            } else help += s[i];
        }
        for (int j = std::size(help) - 1; j >= 0; j--) {
            ret += help[j];
        }
        return ret;
    }
};

