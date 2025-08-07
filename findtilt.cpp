class Solution {
public:
    int totalTilt = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int leftSum = dfs(node->left);
        int rightSum = dfs(node->right);

        int tilt = std::abs(leftSum - rightSum);
        totalTilt += tilt;

        return node->val + leftSum + rightSum;
    }

    int findTilt(TreeNode* root) {
        dfs(root);
        return totalTilt;
    }
};
