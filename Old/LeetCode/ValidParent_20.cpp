#include <string>
#include <stack>
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for(int i = 0; i < std::size(s);i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stack.push(s[i]);
            else{
                if(stack.empty()) return false;
                char check = stack.top();
                stack.pop();
                if(check == '(' && s[i] != ')') return false;
                if(check == '[' && s[i] != ']') return false;
                if(check == '{' && s[i] != '}') return false;
            }
        }
        if(stack.empty()) return true;
        else return false;
    }
};