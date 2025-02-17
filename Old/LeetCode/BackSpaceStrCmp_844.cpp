#include <string>

class Solution {
public:
    bool backspaceCompare(std::string s, std::string t) {
        while(s[0] == '#') s.erase(0, 1);
        while(t[0] == '#') t.erase(0, 1);
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                s.erase(i-1, 2);
                i-=2;
            }
            while(s[0] == '#') s.erase(0, 1);
        }
        for(int i = 0; i <t.size(); i++){
            if(t[i] == '#'){
                t.erase(i-1, 2);
                i-=2;
            }
            while(t[0] == '#') t.erase(0, 1);
        }
        return s == t;
    }
};