#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int>seen;
        while(n!=1 && seen.find(n) == seen.end()){
            seen.insert(n);
            int sum = 0;
            while(n>0){
                int d = n % 10;
                sum+=d*d;
                n/=10;
            }
            n = sum;
        }
        return n == 1;
    }
};