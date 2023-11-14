#include "string"

class Solution {
public:
    std::string strWithout3a3b(int a, int b) {
        std::string ret = "";
        int cnta = 0;
        int cntb = 0;
        while(a+b != 0){
            if(a > b && cnta != 2){
                ret+='a';
                cnta++;
                cntb=0;
                a--;
            }
            else if(cntb != 2){
                ret+='b';
                cntb++;
                cnta = 0;
                b--;
            }
            else{
                ret+='a';
                cnta++;
                cntb = 0;
                a--;
            }
        }
        return ret;
    }
};