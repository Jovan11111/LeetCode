#include "vector"

class SeatManager {
public:
    SeatManager(int n) {
        for(int i = 0; i < n; i++){seats.push_back(i+1);}
    }

    int reserve() {
        for(int i = 0; i < seats.size(); i++){
            if(seats[i] != 0) {seats[i] = 0;return i+1;}
        }
        return 0;
    }

    void unreserve(int seatNumber) {
        seats[seatNumber-1] = seatNumber;
    }
private:
    std::vector<int> seats;
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */