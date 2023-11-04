#include "vector"

class Solution {
public:
    int getLastMoment(int n, std::vector<int>& left, std::vector<int>& right) {
        return (left.empty() ? 0 : *std::max_element(left.begin(), left.end()))>(right.empty() ? 0 : n - *std::min_element(right.begin(), right.end()))?(left.empty() ? 0 : *std::max_element(left.begin(), left.end())):(right.empty() ? 0 : n - *std::min_element(right.begin(), right.end()));
    }
};
