#include "vector"

class Solution {
public:
    std::vector<int> findArray(std::vector<int>& pref) {
        std::vector<int> ret(pref.size(), 0);
        ret[0] = pref[0];

        for(int i =1; i < ret.size();i++){
            ret[i] = pref[i] ^ pref[i-1];
        }

        return ret;
    }
};