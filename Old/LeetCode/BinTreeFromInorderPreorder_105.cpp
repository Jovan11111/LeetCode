#include <vector>
#include <unordered_map>
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
    TreeNode *buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        std::unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); i++) {
            inorder_map[inorder[i]] = i;
        }

        int preorder_index = 0;
        return buildTreeHelper(preorder, inorder_map, 0, inorder.size() - 1, preorder_index);
    }

private:
    TreeNode *buildTreeHelper(std::vector<int> &preorder, std::unordered_map<int, int> &inorder_map, int inorder_start,
                              int inorder_end, int &preorder_index) {
        if (inorder_start > inorder_end) {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preorder_index]);
        preorder_index++;

        int inorder_index = inorder_map[root->val];

        root->left = buildTreeHelper(preorder, inorder_map, inorder_start, inorder_index - 1, preorder_index);
        root->right = buildTreeHelper(preorder, inorder_map, inorder_index + 1, inorder_end, preorder_index);

        return root;
    }
};