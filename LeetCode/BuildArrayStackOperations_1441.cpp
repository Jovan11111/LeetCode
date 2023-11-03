#include "string"
#include "vector"

class Solution {
public:
    std::vector<std::string> buildArray(std::vector<int>& target, int n) {
        std::vector<std::string> ret;
        int ind = 0;
        int i = 1;
        while(ind < target.size()){
            if(target[ind] == i){
                ind++;
                ret.push_back("Push");
            }
            else{
                ret.push_back("Push");
                ret.push_back("Pop");
            }
            i++;
        }
        return ret;
    }
};