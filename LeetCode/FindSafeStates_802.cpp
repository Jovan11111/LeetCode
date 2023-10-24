#include <vector>

class Solution {
public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        std::vector<int> temp(n, 0);

        for (int i = 0; i < n; i++) {
            if (graph[i].empty()) {
                temp[i] = 1;
            }
        }

        bool madeChanges = true;
        while (madeChanges) {
            madeChanges = false;
            for (int i = 0; i < n; i++) {
                if (temp[i] == 1) continue;

                bool allNeighborsSafe = true;
                for (int neighbor: graph[i]) {
                    if (temp[neighbor] == 0) {
                        allNeighborsSafe = false;
                        break;
                    }
                }

                if (allNeighborsSafe) {
                    temp[i] = 1;
                    madeChanges = true;
                }
            }
        }

        std::vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (temp[i] == 1) {
                ret.push_back(i);
            }
        }

        return ret;
    }
};
