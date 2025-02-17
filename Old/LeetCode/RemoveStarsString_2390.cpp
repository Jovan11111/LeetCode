#include <string>
class Solution {
public:
    std::string removeStars(std::string s) {
        std::string ret = "";
        for(int i = 0; i < std::size(s);i++){
            if(s[i] == '*'){
                ret.pop_back();
            }
            else ret+=s[i];
        }
        return ret;
    }
};