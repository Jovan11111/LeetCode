#include <string>
class Solution {
public:
    bool winnerOfGame(std::string colors) {
        int a = 0;
        int b = 0;
        if(std::size(colors)< 3) return false;
        for(int i = 0; i < std::size(colors) - 2; i++){
            if(colors[i] == 'A' && colors[i+1] == 'A' && colors[i+2] == 'A') a++;
            if(colors[i] == 'B' && colors[i+1] == 'B' && colors[i+2] == 'B') b++;
        }
        if(a > b) return true;
        else return false;
    }
};