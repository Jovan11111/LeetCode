#include <vector>

//  Definition for a binary tree node.
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
    TreeNode *sortedArrayToBST(std::vector<int> &nums) {
        TreeNode *root = bstMaker(0, nums.size() - 1, nums);
        return root;
    }

private:
    TreeNode *bstMaker(int low, int high, std::vector<int> &nums) {
        if (low > high) return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = bstMaker(low, mid - 1, nums);
        root->right = bstMaker(mid + 1, high, nums);
        return root;
    }
};