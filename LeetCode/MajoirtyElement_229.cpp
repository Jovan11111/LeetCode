#include <vector>

class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int n = std::size(nums)/3;
        std::sort(nums.begin(), nums.end());
        int cnt = 1;
        int num = nums[0];
        std::vector<int> ret;
        for(int i = 1; i < std::size(nums);i++){
            if(nums[i] == num) cnt++;
            else{
                if(cnt > n) ret.push_back(num);
                cnt = 1;
                num = nums[i];
            }
        }
        if(cnt > n) ret.push_back(num);
        return ret;
    }
};