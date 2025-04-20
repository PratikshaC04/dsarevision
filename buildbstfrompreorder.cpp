class Solution {
public:
    TreeNode* buildBST(vector<int>& preorder, int& idx, int minVal, int maxVal) {
        if (idx >= preorder.size()) return nullptr;

        int currVal = preorder[idx];
        if (currVal < minVal || currVal > maxVal) return nullptr;

        TreeNode* root = new TreeNode(currVal);
        idx++;

        // Left subtree: values < currVal
        root->left = buildBST(preorder, idx, minVal, currVal - 1);
        // Right subtree: values > currVal
        root->right = buildBST(preorder, idx, currVal + 1, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return buildBST(preorder, idx, INT_MIN, INT_MAX);
    }
};

