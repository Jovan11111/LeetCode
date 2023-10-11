#include <vector>
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> mapa;
        for(int i = 0; i < nums.size();i++) mapa.insert(nums[i]);

        int max = 0;

        for(int num : mapa){
            if(mapa.find(num-1) == mapa.end()){
                int cur = 1;
                int curnum = num;
                while(mapa.find(curnum+1) != mapa.end()){
                    curnum++;
                    cur++;
                }
                max = cur > max ? cur : max;
            }
        }
        return max;
    }
};