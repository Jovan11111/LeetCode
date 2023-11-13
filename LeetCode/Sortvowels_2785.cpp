#include "string"

class Solution {
public:
    std::string sortVowels(std::string s) {
        std::string help = "";
        std::string vovs = "";
        for(int i  = 0 ; i < s.size() ; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
               s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){help+='b';vovs+=s[i];}
            else help += 'a';
        }
        std::sort(vovs.begin(), vovs.end());
        int cnt = 0;
        for(int i = 0; i < s.size();i++){
            if(help[i] == 'b') s[i] = vovs[cnt++];
        }
        return s;
    }
};