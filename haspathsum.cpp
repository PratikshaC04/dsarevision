class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;

        // If it's a leaf node
        if (!root->left && !root->right) {
            return root->val == targetSum;
        }

        // Check left and right subtrees with the reduced target sum
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
