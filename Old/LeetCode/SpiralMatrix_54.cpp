#include <vector>
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> ret;
        int g = 0;
        int l = 0;
        int d = matrix.size() - 1;
        int de = matrix.empty() ? -1 : matrix[0].size() - 1;
        while (g <= d && l <= de) {
            for (int i = l; i <= de; i++) {
                ret.push_back(matrix[g][i]);
            }
            g++;
            for (int i = g; i <= d; i++) {
                ret.push_back(matrix[i][de]);
            }
            de--;
            if (g <= d) {
                for (int i = de; i >= l; i--) {
                    ret.push_back(matrix[d][i]);
                }
                d--;
            }
            if (l <= de) {
                for (int i = d; i >= g; i--) {
                    ret.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return ret;
    }
};
