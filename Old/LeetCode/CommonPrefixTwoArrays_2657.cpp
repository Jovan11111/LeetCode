#include "vector"
#include "unordered_map"

class Solution {
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) {
        int n = A.size();
        std::unordered_map<int, bool> mapaA;
        std::unordered_map<int, bool> mapaB;
        std::vector<int>C;

        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            mapaA[A[i]-1] = true;
            mapaB[B[i]-1] = true;
            if(mapaA[A[i]-1] and mapaB[A[i]-1]) cnt++;
            if(A[i] != B[i]) if(mapaA[B[i]-1] and mapaB[B[i]-1]) cnt++;
            C.push_back(cnt);
        }

        return C;
    }
};