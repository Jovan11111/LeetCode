#include "vector"
#include "unordered_map"
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> findMode(TreeNode *root) {
        std::unordered_map<int, int> mapa;
        int max = 0;
        std::vector<int> ret;

        searchTree(root, mapa, max);

        for (const auto &i: mapa) {
            if (i.second == max) {
                ret.push_back(i.first);
            }
        }
        return ret;
    }

    void searchTree(TreeNode *root, std::unordered_map<int, int> &mapa, int &max) {
        if (!root) return;

        searchTree(root->left, mapa, max);

        mapa[root->val]++;
        max = max > mapa[root->val] ? max : mapa[root->val];

        searchTree(root->right, mapa, max);
    }
};