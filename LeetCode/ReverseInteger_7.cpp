#include <string>
class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x == INT_MIN) return 0;
        if(x < 0){neg = true; x*=-1;}
        std::string s = std::to_string(x);
        std::reverse(s.begin(), s.end());
        try{
            return neg ? -1*stoi(s) : stoi(s);
        }
        catch(const std::exception& e)
        {
            return 0;
        }
    }
};