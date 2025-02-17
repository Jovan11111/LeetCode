#include <string>
class Solution {
public:
    int partitionString(std::string s) {
        int l = 0;
        int r = 1;
        int cnt = 0;
        while(r < s.size()){
            bool check = false;
            for(int i = l; i < r ; i++){
                if(s[i] == s[r]){
                    l = r;
                    r = l+1;
                    cnt++;
                    check = true;
                    break;
                }
            }
            if(!check) r++;
        }
        return cnt+1;
    }
};