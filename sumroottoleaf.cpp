

class Solution {
public:
    // This is the main function called by LeetCode.
    // It initializes the DFS traversal.
    int sumNumbers(TreeNode* root) {
        // Start the Depth-First Search from the root node.
        // The initial 'current_num' is 0, as we haven't processed any digits yet.
        return dfs(root, 0);
    }

private:
    // Helper function for Depth-First Search traversal.
    // 'node': The current node being visited.
    // 'current_num': The number formed by the path from the root down to the parent of the 'node'.
    int dfs(TreeNode* node, int current_num) {
        // Base case 1: If the current node is null, it means we've gone off a branch.
        // This path doesn't contribute to the sum, so return 0.
        if (node == nullptr) {
            return 0;
        }

        // Update the 'current_num' by appending the digit of the current node.
        // Example: if current_num was 12 and node->val is 3, new current_num becomes 123.
        current_num = current_num * 10 + node->val;

        // Base case 2: If the current node is a leaf node.
        // A leaf node has no left child AND no right child.
        if (node->left == nullptr && node->right == nullptr) {
            // We've reached the end of a root-to-leaf path.
            // The 'current_num' now represents the complete number for this path.
            return current_num;
        }

        // Recursive step: If it's not a leaf node,
        // sum the results from its left and right subtrees.
        // Pass the updated 'current_num' to the children.
        int left_subtree_sum = dfs(node->left, current_num);
        int right_subtree_sum = dfs(node->right, current_num);

        // The total sum from this node's branch is the sum of paths from its children.
        return left_subtree_sum + right_subtree_sum;
    }
};