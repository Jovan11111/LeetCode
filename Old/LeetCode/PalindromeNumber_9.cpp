#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::vector<int> temp;

        while (x >= 10) {
            temp.push_back(x % 10);
            x /= 10;
        }

        temp.push_back(x);

        x = 0;
        int right = temp.size() - 1;

        while (x < right) {
            if (temp[x] != temp[right]) return false;
            x++;
            right--;
        }

        return true;
    }
};
