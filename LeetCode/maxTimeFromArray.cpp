#include "vector"
#include "string"

class Solution {
public:
    std::string largestTimeFromDigits(std::vector<int>& arr) {
        std::string ret;
        std::sort(arr.begin(), arr.end(), std::greater<int>());

        do {
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];

            if (hours < 24 && minutes < 60) {
                ret = (hours < 10 ? "0" : "") + std::to_string(hours) + ":" + (minutes < 10 ? "0" : "") + std::to_string(minutes);
                return ret;
            }
        } while (std::prev_permutation(arr.begin(), arr.end()));

        return "";
    }
};
