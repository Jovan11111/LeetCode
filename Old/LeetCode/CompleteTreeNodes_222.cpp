
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
    bool first = false;

    int countNodes(TreeNode *root) {
        if (!root) return 0;
        int l = 0;
        if (!first) {
            l++;
            first = true;
        }

        if (root->left) l++;
        if (root->right) l++;
        l += countNodes(root->left);
        l += countNodes(root->right);
        return l;
    }
};