class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            return new TreeNode(val);
        }
        TreeNode* t = root;
        while (t != NULL) {
            if (t->val <= val) {
                if (t->right != NULL)
                    t = t->right;
                else {
                    t->right = new TreeNode(val);
                    break;
                }
            }
            else {
                if (t->left != NULL)
                    t = t->left;
                else {
                    t->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

