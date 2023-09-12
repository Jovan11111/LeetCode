#include <vector>
class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int start_point = -1;
        int gass = 0;
        int cur = 0;
        for(int i = 0; i < std::size(gas);i++){
            int temp = gas[i] - cost[i];
            gass += temp;
            cur += temp;
            if(cur < 0){
                start_point = i;
                cur = 0;
            }
        }
        if(gass<0) return -1;
        return start_point+1;
    }

};
