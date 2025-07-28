
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> modes;
        TreeNode* prev = nullptr;
        int currentCount = 0;
        int maxCount = 0;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if (!node) return;

            inorder(node->left);

            // Update current count
            if (prev && prev->val == node->val) {
                currentCount++;
            } else {
                currentCount = 1;
            }

            // Update modes
            if (currentCount > maxCount) {
                maxCount = currentCount;
                modes = {node->val};
            } else if (currentCount == maxCount) {
                modes.push_back(node->val);
            }

            prev = node;
            inorder(node->right);
        };

        inorder(root);
        return modes;
    }
};
