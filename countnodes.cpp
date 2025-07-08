class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftHeight = getHeight(root, true);
        int rightHeight = getHeight(root, false);

        if (leftHeight == rightHeight) {
            // Perfect binary tree
            return (1 << leftHeight) - 1;
        } else {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }
    }

    int getHeight(TreeNode* node, bool left) {
        int height = 0;
        while (node) {
            height++;
            node = left ? node->left : node->right;
        }
        return height;
    }
};
