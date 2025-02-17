#include <string>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs) {
        std::string s = strs[0];
        for (int i = 1; i < std::size(strs); i++) {
            std::string h = "";
            for (int j = 0; j < std::size(strs[i]) or j < std::size(s); j++) {
                if(s[j] == strs[i][j]) h+= s[j];
                else break;
            }
            s = h;
        }
        return s;
    }
};