#include "string"

class Solution {
public:
    int maxVowels(std::string s, int k) {
        int l = 0;
        int r = k-1;
        int cnt = 0;
        int mac = 0;
        for(int i = 0; i <= r; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt++;
        }

        while(r < s.size()){
            if(cnt > mac) mac = cnt;
            if(s[r+1] == 'a' || s[r+1] == 'e' || s[r+1] == 'i' || s[r+1] == 'o' || s[r+1] == 'u')cnt++;
            if(s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') cnt--;

            l++;
            r++;
        }
        return mac;
    }
};