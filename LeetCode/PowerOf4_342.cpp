class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 4) return true;
        long long x = 4;
        while(x < n){
            x*=4;
            if(x == n) return true;
        }
        return false;
    }
};