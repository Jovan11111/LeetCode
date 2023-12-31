#include <vector>
#include <stack>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector <NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(std::vector <NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            nestedStack.push(nestedList[i]);
        }
    }

    int next() {
        if (!hasNext()) {
            return -1;
        }

        int ret = nestedStack.top().getInteger();
        nestedStack.pop();
        return ret;
    }

    bool hasNext() {
        while (!nestedStack.empty()) {
            if (nestedStack.top().isInteger()) {
                return true;
            } else {
                auto nestedList = nestedStack.top().getList();
                nestedStack.pop();
                for (int i = nestedList.size() - 1; i >= 0; i--) {
                    nestedStack.push(nestedList[i]);
                }
            }
        }

        return false;
    }

private:
    std::stack <NestedInteger> nestedStack;
};

