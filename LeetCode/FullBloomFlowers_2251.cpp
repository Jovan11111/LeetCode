#include <vector>
#include <map>
class Solution {
public:
    std::vector<int> fullBloomFlowers(std::vector<std::vector<int>>& flowers, std::vector<int>& people) {
        std::vector<int> result;
        std::map<int, int> bloomCount;

        for (const auto& flower : flowers) {
            bloomCount[flower[0]]++;
            bloomCount[flower[1] + 1]--;
        }

        int count = 0;
        for (const auto& entry : bloomCount) {
            count += entry.second;
            bloomCount[entry.first] = count;
        }

        for (int time : people) {
            auto it = bloomCount.upper_bound(time);
            if (it != bloomCount.begin()) {
                --it;
                result.push_back(it->second);
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};
