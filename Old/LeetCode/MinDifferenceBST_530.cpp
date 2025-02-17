// Definition for a binary tree node.
#include <vector>
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
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        TreeNode* prevNode = nullptr;

        inorderTraversal(root, prevNode, minDiff);

        return minDiff;
    }

    void inorderTraversal(TreeNode* node, TreeNode*& prevNode, int& minDiff) {
        if (node == nullptr) return;

        inorderTraversal(node->left, prevNode, minDiff);

        if (prevNode != nullptr) {
            minDiff = std::min(minDiff, std::abs(node->val - prevNode->val));
        }

        prevNode = node;

        inorderTraversal(node->right, prevNode, minDiff);
    }
};