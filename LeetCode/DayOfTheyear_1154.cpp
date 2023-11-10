#include "vector"
#include "string"
#include <sstream>


class Solution {
public:
    int dayOfYear(std::string date) {
        std::vector<int> months = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        std::stringstream ss(date);
        char del = '-';
        int year;
        int month;
        int day;
        ss >> year >> del >> month >> del >> day;
        return months[month-1]+day+ (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month> 2? 1 : 0);
    }
};