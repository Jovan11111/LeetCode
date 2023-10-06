#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool wordPattern(std::string pattern, std::string s) {
        std::vector<std::string> words;
        std::string help = "";
        for (int i = 0; i < std::size(s); i++) {
            if (s[i] == ' ') {
                words.push_back(help);
                help = "";
            } else help += s[i];
        }
        words.push_back(help);
        if (words.size() != pattern.size()) return false;

        std::unordered_map<char, std::string> mapa;
        std::unordered_map<std::string, char> mapa1;

        for(int i = 0; i < pattern.size();i++){
            if(mapa.find(pattern[i]) != mapa.end()){
                if(mapa[pattern[i]] != words[i]) return false;
            }
            else mapa[pattern[i]] = words[i];

            if(mapa1.find(words[i]) != mapa1.end()){
                if(mapa1[words[i]] != pattern[i]) return false;
            }
            else mapa1[words[i]] = pattern[i];
        }
        return true;

    }
};