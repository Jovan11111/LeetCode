#include <string>
class Solution {
public:
    std::string mergeAlternately(std::string word1, std::string word2) {
        int n = word1.size() < word2.size() ? word1.size() : word2.size();
        int v = word1.size() < word2.size() ? word2.size() : word1.size();
        bool c = word1.size() > word2.size() ? true : false;
        std::string ret = "";
        for(int i = 0; i < n;i++){
            ret+=word1[i];
            ret+=word2[i];
        }
        for(int i = n; i < v;i++){
            if(c)ret+=word1[i];
            else ret+=word2[i];
        }
        return ret;

    }
};