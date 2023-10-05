#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int l = 0;
        int h = std::size(numbers)-1;
        while(l < h){
            if(numbers[l] + numbers[h] == target) return {l+1, h+1};
            else if(numbers[l] + numbers[h] > target) h--;
            else l++;
        }
        return {};
    }
};