#include "vector"
#include "string"

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string ret = s;
        for(int i  = 0; i < indices.size() ; i++){
            ret[indices[i]] = s[i];
        }
        return ret;

    }
};