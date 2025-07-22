class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent; // to store parent links
    unordered_set<TreeNode*> visited;

    void markParents(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        markParents(root);

        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int curr_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (curr_level == k) break;
            curr_level++;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();

                if (node->left && !visited.count(node->left)) {
                    visited.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !visited.count(node->right)) {
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && !visited.count(parent[node])) {
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
