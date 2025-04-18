class Solution {
public:
    void inorder(TreeNode* root, int& counter, int k, int& result) {
        if (!root) return;

        inorder(root->left, counter, k, result);

        counter++;
        if (counter == k) {
            result = root->val;
            return;
        }

        inorder(root->right, counter, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int result = -1;
        inorder(root, counter, k, result);
        return result;
    }
};

