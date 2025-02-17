#include <stack>
class MinStack {
public:
    MinStack() {
    }

    void push(int val) {
        stack.push(val);
        if(min.empty() || val <= min.top()){
            min.push(val);
        }
    }

    void pop() {
        if(stack.top() == min.top()) min.pop();
        stack.pop();
    }

    int top() {
        return stack.top();
    }

    int getMin() {
        return min.top();
    }
private:
    std::stack<int> min;
    std::stack<int> stack;
};