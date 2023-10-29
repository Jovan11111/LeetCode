#include <unordered_map>
#include <string>

class Solution {
public:
    int canBeTypedWords(std::string text, std::string brokenLetters) {
        std::unordered_map<char, int> broken;
        for(int i = 0; i < brokenLetters.size();i++) broken[brokenLetters[i]] = 1;

        int ret = 1;
        bool allreadyBroken = false;

        for(int i = 0; i < text.size();i++){
            if(broken.find(text[i]) != broken.end() && !allreadyBroken) {ret--;allreadyBroken = true;}
            if(text[i] == ' ') {ret++;allreadyBroken = false;}
        }

        return ret < 0 ? 0 : ret;
    }
};