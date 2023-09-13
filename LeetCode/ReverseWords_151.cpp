#include <string>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::vector<std::string> strs;
        std::string help = "";
        for (char c: s) {
            if(c == ' '){
                if(help != "")strs.push_back(help);
                help = "";

            }
            else help+=c;
        }
        if(help != "") strs.push_back(help);
        std::string ret = "";
        for(int i = std::size(strs)-1; i >=0;i--){
            ret+=strs[i];
            if(i != 0) ret+= " ";
        }
        return ret;
    }
};


