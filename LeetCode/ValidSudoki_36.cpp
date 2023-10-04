#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<int>> pr1(9, std::vector<int>(9, 0));
        std::vector<std::vector<int>> pr2(9, std::vector<int>(9, 0));
        std::vector<std::vector<int>> pr3(9, std::vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    if (pr1[i][num] == 1 || pr2[j][num] == 1 || pr3[i / 3 * 3 + j / 3][num] == 1) {
                        return false;
                    }
                    pr1[i][num] = 1;
                    pr2[j][num] = 1;
                    pr3[i / 3 * 3 + j / 3][num] = 1;
                }
            }
        }

        return true;
    }
};
