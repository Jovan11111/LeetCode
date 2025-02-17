#include <string>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int ret = 0;
        int ch = 0;
        for (char c: s) {
            if (c == ' ') {
                if(ret != 0) ch = ret;
                ret = 0;
            } else {
                ret++;
            }
        }
        return ret == 0 ? ch: ret;
    }
};