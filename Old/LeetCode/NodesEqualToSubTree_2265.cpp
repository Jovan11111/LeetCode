
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
    int averageOfSubtree(TreeNode *root) {
        int cnt = 0;
        postorderSum(root, cnt);
        return cnt;
    }

private:
    int postorderSum(TreeNode *root, int &cnt) {
        if (!root) return 0;

        int left = postorderSum(root->left, cnt);
        int right = postorderSum(root->right, cnt);

        int left_cnt = postorderCnt(root->left);
        int right_cnt = postorderCnt(root->right);

        int sum = root->val + left + right;
        int count = 1 + left_cnt + right_cnt;

        if (sum / count == root->val) cnt++;

        return sum;
    }

    int postorderCnt(TreeNode *root) {
        if (!root) return 0;

        int left_cnt = postorderCnt(root->left);
        int right_cnt = postorderCnt(root->right);

        return 1 + left_cnt + right_cnt;
    }
};