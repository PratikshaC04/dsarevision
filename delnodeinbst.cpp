class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        if (key < root->val)
            root->left = deleteNode(root->left, key);
        else if (key > root->val)
            root->right = deleteNode(root->right, key);
        else {
            // Found the node to delete

            // Case 1: No child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // Case 2: One child (right)
            else if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // Case 3: One child (left)
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 4: Two children
            else {
                TreeNode* succ = findMin(root->right);
                root->val = succ->val;
                root->right = deleteNode(root->right, succ->val);
            }
        }
        return root;
    }

    // Helper to find the minimum value node in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != NULL)
            node = node->left;
        return node;
    }
};
