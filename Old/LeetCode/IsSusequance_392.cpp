#include <string>
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        if(s == "") return true;
        int ind = 0;
        for(int i = 0; i < std::size(t);i++){
            if(s[ind] == t[i]) ind++;
            if(ind == std::size(s)) return true;
        }
        return false;
    }
};