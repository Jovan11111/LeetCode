#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        if (rowIndex == 0) return {1};
        if (rowIndex == 1) return {1, 1};
        std::vector<int> ret = {1, 1};
        for (int i = 0; i < rowIndex - 1; i++) {
            std::vector<int> temp = {1};
            for (int j = 0; j < ret.size() - 1; j++) {
                temp.push_back(ret[j] + ret[j + 1]);
            }
            temp.push_back(1);
            ret = temp;
        }
        return ret;
    }
};