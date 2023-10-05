#include <string>
#include <unordered_map>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::unordered_map<char, int> freq;
        for(int i = 0; i < std::size(magazine);i++){
            freq[magazine[i]]++;
        }
        for(int i = 0; i <std::size(ransomNote);i++){
            if(freq[ransomNote[i]] > 0) freq[ransomNote[i]]--;
            else return false;
        }
        return true;
    }
};

