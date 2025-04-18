class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) 
            return nullptr;
        
        int currVal = root->val;

        // Both nodes in left subtree
        if (currVal > p->val && currVal > q->val)
            return lowestCommonAncestor(root->left, p, q);

        // Both nodes in right subtree
        if (currVal < p->val && currVal < q->val)
            return lowestCommonAncestor(root->right, p, q);

        // Split point found (or one of p or q is root)
        return root;
    }
};

