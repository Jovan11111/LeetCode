#include <string>
#include <vector>
#include <stack>
#include <cstdlib>


class Solution {
public:
    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<int> stack;

        for (int i = 0; i < tokens.size(); i++) {
            if (isNumber(tokens[i])) {
                stack.push(std::stoi(tokens[i]));
            } else {
                if (stack.size() < 2) {
                    return INT_MIN;
                }

                int a = stack.top();
                stack.pop();
                int b = stack.top();
                stack.pop();
                int val;

                if (tokens[i] == "+") {
                    val = b + a;
                } else if (tokens[i] == "-") {
                    val = b - a;
                } else if (tokens[i] == "*") {
                    val = b * a;
                } else if (tokens[i] == "/") {
                    val = b / a;
                }

                stack.push(val);
            }
        }

        return stack.top();
    }

    bool isNumber(const std::string& str) {
        try {
            std::stoi(str);
            return true;
        } catch (const std::invalid_argument& e) {
            return false;
        }
    }
};
