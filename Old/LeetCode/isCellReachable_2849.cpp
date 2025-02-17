#include "vector"

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy)
            if (t != 1) return true;
            else { return false; }
        int m = std::abs(sx-fx) > std::abs(sy-fy) ? std::abs(sx-fx) : std::abs(sy-fy);
        if (m <= t) {
            return true;
        } else {
            return false;
        }
    }
};
