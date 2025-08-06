class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (root) dfs(root, "", result);
        return result;
    }

private:
    void dfs(TreeNode* node, string path, vector<string>& result) {
        if (!node) return;

        path += to_string(node->val);

        if (!node->left && !node->right) {
            result.push_back(path);  // Leaf node
        } else {
            path += "->";
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }
    }
};
