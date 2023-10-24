#include <vector>
#include <queue>
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
    std::vector<int> largestValues(TreeNode *root) {
        std::vector<int> ret;
        if (!root) return ret;
        std::queue < TreeNode * > q;
        q.push(root);

        while (!q.empty()) {
            int max = INT_MIN;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *temp = q.front();
                q.pop();
                max = max > temp->val ? max : temp->val;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            ret.push_back(max);
        }
        return ret;
    }
};