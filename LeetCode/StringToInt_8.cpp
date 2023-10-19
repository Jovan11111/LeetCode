#include <string>
#include <stdexcept>
class Solution {
public:
    int myAtoi(std::string s) {
        while(std::isspace(s[0])) s.erase(0, 1);
        try{
            return stoi(s);
        }
        catch(const std::out_of_range& e){
            if(s[0] == '-') return INT_MIN;
            else return INT_MAX;
        }
        catch(const std::invalid_argument& e){
            return 0;
        }
    }
};