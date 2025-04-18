class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool helper(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;
        
        if (root->val <= minVal || root->val >= maxVal)
            return false;
        
        return helper(root->left, minVal, root->val) && 
               helper(root->right, root->val, maxVal);
    }
};

