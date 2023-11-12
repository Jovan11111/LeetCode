#include "vector"
#include "unordered_map"

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::unordered_map<int, int> mapa;
        if(trust.size() == 0 && n == 1) return 1;
        int cnt = 0;
        for(int i = 0; i < trust.size();i++){
            if(mapa.find(trust[i][1]) != mapa.end()) mapa[trust[i][1]]++;
            else mapa[trust[i][1]] = 1;
            if(mapa.find(trust[i][0]) != mapa.end()) mapa[trust[i][0]]--;
            else mapa[trust[i][0]] = -1;
        }
        for(auto& e: mapa){
            if(e.second == n-1) return e.first;
        }
        return -1;
    }
};