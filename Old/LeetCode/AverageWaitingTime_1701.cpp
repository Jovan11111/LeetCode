#include "vector"

class Solution {
public:
    double averageWaitingTime(std::vector<std::vector<int>>& customers) {
        int time = customers[0][0];
        double sum = 0;
        for(int i = 0 ; i < customers.size(); i++){
            time = time > customers[i][0] ? time : customers[i][0];
            sum += time-customers[i][0] > 0 ? time-customers[i][0] + customers[i][1] : customers[i][1];
            time+=customers[i][1];
        }
        return sum/customers.size();;
    }
};