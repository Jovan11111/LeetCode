#include "string"
#include "vector"

class Solution {
public:
    int garbageCollection(std::vector<std::string>& garbage, std::vector<int>& travel) {
        int p = 0;
        int proute = 0;
        int g = 0;
        int groute = 0;
        int m = 0;
        int mroute = 0;
        for(int i = 0 ; i < garbage.size();i++){
            p += std::count(garbage[i].begin(), garbage[i].end(), 'P');
            m += std::count(garbage[i].begin(), garbage[i].end(), 'M');
            g += std::count(garbage[i].begin(), garbage[i].end(), 'G');
            if(i != garbage.size()-1){
                if(std::count(garbage[i+1].begin(), garbage[i+1].end(), 'P') == 0) proute+=travel[i];
                else {p+=travel[i]+proute; proute = 0;}

                if(std::count(garbage[i+1].begin(), garbage[i+1].end(), 'M') == 0) mroute+=travel[i];
                else {m+=travel[i]+mroute; mroute = 0;}

                if(std::count(garbage[i+1].begin(), garbage[i+1].end(), 'G') == 0) groute+=travel[i];
                else {g+=travel[i]+groute; groute = 0;}
            }
        }
        return p + m + g;
    }
};