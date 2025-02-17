
// Definition for a binary tree node.
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
    int n;

    int kthSmallest(TreeNode *root, int k) {
        if (!root) return -1;
        int x = kthSmallest(root->left, k);
        if (x != -1) return x;
        n++;
        if (n == k) return root->val;
        int y = kthSmallest(root->right, k);
        if (y != -1) return y;
        return -1;
    }
};