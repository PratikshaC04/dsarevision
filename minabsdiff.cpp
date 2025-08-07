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
    int minDiff = INT_MAX;
    int prevVal = -1;

    void inOrder(TreeNode* root) {
        if (!root) return;

        inOrder(root->left);

        if (prevVal != -1) {
            minDiff = min(minDiff, abs(root->val - prevVal));
        }
        prevVal = root->val;

        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        return minDiff;
    }
};

    
