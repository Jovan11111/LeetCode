class Solution {
public:
    int kthFactor(int n, int k) {
        if(k == 1) return 1;
        k--;
        k--;
        for(int i = 2; i < n/2+1 ; i++){
            if( n%i == 0 ){
                if(k == 0) return i;
                k--;
            }
        }
        if(k == 0) return n;
        return -1;
    }
};

