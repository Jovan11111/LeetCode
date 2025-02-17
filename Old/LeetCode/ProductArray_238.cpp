#include <vector>

class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> answer(std::size(nums));
        int proizvod = 1;
        int proizvod_nula = 1;
        int brnula = 0;
        for(int i = 0; i < std::size(nums); i++){
            proizvod*= nums[i];
            if(nums[i] != 0) proizvod_nula *= nums[i];
            else brnula++;
        }
        std::fill(answer.begin(), answer.end(), proizvod);
        for(int i = 0; i <std::size(nums);i++){
            if(nums[i] != 0) answer[i] /= nums[i];
            else if(brnula < 2) answer[i] = proizvod_nula;
            else answer[i] = 0;
        }
        return answer;
    }
};