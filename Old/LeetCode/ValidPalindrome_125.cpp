#include <string>
class Solution {
public:
    bool isPalindrome(std::string s) {
        int b = 0;
        int e = std::size(s)-1;
        while(b < e){
            while(!std::isalnum(s[b]) && b < e)b++;
            while(!std::isalnum(s[e]) && b < e)e--;
            if(std::isupper(s[b]))s[b] = std::tolower(s[b]);
            if(std::isupper(s[e]))s[e] = std::tolower(s[e]);
            if(s[b] != s[e]) return false;
            b++;
            e--;
        }
        return true;
    }
};
