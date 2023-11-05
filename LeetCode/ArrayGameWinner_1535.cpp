#include "vector"

class Solution {
public:
    int getWinner(std::vector<int>& arr, int k) {
        if(k == 1) return arr[0] > arr[1] ? arr[0] : arr[1];
        if(k > arr.size()) return *std::max_element(arr.begin(), arr.end());

        int cnt = 0;
        while(cnt != k && arr.size() > 2){
            if(arr[0] > arr[1]) {
                cnt++;
                arr.erase(arr.begin() + 1);
            }
            else{
                cnt = 1;
                arr.erase(arr.begin());
            }
        }
        return cnt == k ? arr[0] : arr[0] >arr[1] ? arr[0] : arr[1];
    }
};