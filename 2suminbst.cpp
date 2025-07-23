/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& nums) {
        if (!root) return;
        inOrder(root->left, nums);
        nums.push_back(root->val);
        inOrder(root->right, nums);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root, nums);  // Get sorted array from BST

        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }

        return false;
    }
};
