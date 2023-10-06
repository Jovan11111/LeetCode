#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> mapa;

        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            mapa[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (mapa.find(t[i]) != mapa.end()) {
                if (mapa[t[i]] == 0) return false;
                else mapa[t[i]]--;
            } else {
                return false;
            }
        }
        return true;
    }
};
