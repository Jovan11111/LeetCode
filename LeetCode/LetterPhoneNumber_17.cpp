#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }

        unordered_map<char, string> digitToLetters = {
                {'2', "abc"},
                {'3', "def"},
                {'4', "ghi"},
                {'5', "jkl"},
                {'6', "mno"},
                {'7', "pqrs"},
                {'8', "tuv"},
                {'9', "wxyz"}
        };

        string currentCombination;
        generateCombinations(digits, 0, currentCombination, result, digitToLetters);

        return result;
    }

    void generateCombinations(const string& digits, int index, string& currentCombination, vector<string>& result, const unordered_map<char, string>& digitToLetters) {
        if (index == digits.size()) {
            result.push_back(currentCombination);
            return;
        }

        char currentDigit = digits[index];
        const string& letters = digitToLetters.at(currentDigit);

        for (char letter : letters) {
            currentCombination.push_back(letter);
            generateCombinations(digits, index + 1, currentCombination, result, digitToLetters);
            currentCombination.pop_back();
        }
    }
};

