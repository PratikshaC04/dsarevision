class Solution {
public:
    vector<vector<int>> result;

    void dfs(TreeNode* node, int targetSum, vector<int>& path, int currentSum) {
        if (!node) return;

        // Add current node value to path and update current sum
        path.push_back(node->val);
        currentSum += node->val;

        // If it's a leaf node and the sum matches targetSum, add path to result
        if (!node->left && !node->right && currentSum == targetSum) {
            result.push_back(path);
        }

        // Continue DFS on left and right subtrees
        dfs(node->left, targetSum, path, currentSum);
        dfs(node->right, targetSum, path, currentSum);

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path, 0);
        return result;
    }
};
