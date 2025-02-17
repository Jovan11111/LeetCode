#include <string>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        for(int i = 0; i < s.length(); i++){
            switch (i) {
                case 'I':{
                    if(i != s.length()-1 && s[i+1] == 'V'){
                        ret+=4;
                        i++;
                    }
                    else if(i != s.length()-1 && s[i+1] == 'X') {
                        ret+=9;
                        i++;
                        break;
                    }
                    else ret++;
                    break;
                }
                case 'V': {
                    ret+=5;
                    break;
                }
                case 'X': {
                    if(i != s.length()-1 && s[i+1] == 'L'){
                        ret+=40;
                        i++;
                    }
                    else if(i != s.length()-1 && s[i+1] == 'C') {
                        ret+=90;
                        i++;
                    }
                    else ret+=10;
                    break;
                }
                case 'L': {
                    ret+=50;
                    break;
                }
                case 'C': {
                    if(i != s.length()-1 && s[i+1] == 'D'){
                        ret+=400;
                        i++;
                    }
                    else if(i != s.length()-1 && s[i+1] == 'M') {
                        ret+=900;
                        i++;
                        break;
                    }
                    else ret+=100;
                    break;
                }
                case 'D': {
                    ret+=500;
                    break;
                }
                case 'M': {
                    ret+=1000;
                    break;
                }

            }
        }
        return ret;
    }
};
