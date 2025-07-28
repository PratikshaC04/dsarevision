/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // This pointer will keep track of the previously visited node in the
    // flattened list (in reverse pre-order traversal).
    TreeNode* prev = nullptr;

public:
    void flatten(TreeNode* root) {
        // Base case: If the current node is null, there's nothing to flatten.
        if (root == nullptr) {
            return;
        }

        // 1. Recursively flatten the right subtree first.
        // This ensures that 'prev' will correctly point to the head
        // of the flattened right subtree when we process the current 'root'.
        flatten(root->right);

        // 2. Recursively flatten the left subtree.
        // After this call, 'prev' will point to the head of the flattened left subtree.
        flatten(root->left);

        // 3. Perform the linking for the current 'root'.
        // The current 'root's right child should point to the previously processed node.
        root->right = prev;

        // 4. The left child of the current 'root' should always be nullptr in the flattened list.
        root->left = nullptr;

        // 5. Update 'prev' to be the current 'root' for the next (parent) recursive call.
        prev = root;
    }
};