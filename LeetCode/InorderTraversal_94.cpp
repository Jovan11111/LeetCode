#include <vector>
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
    std::vector<int> ret;

    std::vector<int> inorderTraversal(TreeNode *root) {
        if (!root) return ret;
        inorderTraversal(root->left);
        ret.push_back(root->val);
        inorderTraversal(root->right);
        return ret;
    }
};