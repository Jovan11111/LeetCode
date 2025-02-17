#include <vector>
#include <string>
class Solution {
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves) {
        std::vector<std::vector<int>> grid(3, std::vector<int>(3, 0));
        for(int i = 0; i < moves.size();i++){
            grid[moves[i][0]][moves[i][1]] = i % 2 == 0 ? 1 : 2;
        }
        if(grid[0][0] == 1){
            if(grid[0][1] == 1 and grid[0][2] == 1) return "A";
            if(grid[1][0] == 1 and grid[2][0] == 1) return "A";
        }
        if(grid[0][0] == 2){
            if(grid[0][1] == 2 and grid[0][2] == 2) return "B";
            if(grid[1][0] == 2 and grid[2][0] == 2) return "B";
        }
        if(grid[2][2] == 1){
            if(grid[2][1] == 1 and grid[2][0] == 1) return "A";
            if(grid[1][2] == 1 and grid[0][2] == 1) return "A";
        }
        if(grid[2][2] == 2){
            if(grid[2][1] == 2 and grid[2][0] == 2) return "B";
            if(grid[1][2] == 2 and grid[0][2] == 2) return "B";
        }
        if(grid[1][1] == 1){
            if(grid[0][0] == 1 and grid[2][2] == 1) return "A";
            if(grid[0][2] == 1 and grid[2][0] == 1) return "A";
            if(grid[1][0] == 1 and grid[1][2] == 1) return "A";
            if(grid[0][1] == 1 and grid[2][1] == 1) return "A";
        }
        if(grid[1][1] == 2){
            if(grid[0][0] == 2 and grid[2][2] == 2) return "B";
            if(grid[0][2] == 2 and grid[2][0] == 2) return "B";
            if(grid[1][0] == 2 and grid[1][2] == 2) return "B";
            if(grid[0][1] == 2 and grid[2][1] == 2) return "B";
        }

        if(moves.size() != 9) return "Pending";
        return "Draw";

    }
};