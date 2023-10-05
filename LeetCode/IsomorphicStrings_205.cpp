#include <unordered_map>
#include <string>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if(std::size(s) != std::size(t))return false;

        std::unordered_map<char, char> mapa;
        std::unordered_map<char, char> mapa2;
        for(int i = 0; i < std::size(s);i++){
            if(mapa.find(s[i]) != mapa.end()){
                if(mapa[s[i]] != t[i]) return false;
            }
            else mapa[s[i]] = t[i];

            if(mapa2.find(t[i]) != mapa.end()){
                if(mapa2[t[i]] != s[i]) return false;
            }
            else mapa2[t[i]] = s[i];
        }
        return true;
    }
};