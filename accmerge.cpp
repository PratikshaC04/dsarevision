class Solution {
public:
    class DisjointSet {
        vector<int> parent, rank;
    public:
        DisjointSet(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            }
            else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            }
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    };

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToAccount;

        // Step 1: Union accounts with common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    ds.unionByRank(i, emailToAccount[email]);
                }
            }
        }

        // Step 2: Group emails by parent
        vector<vector<string>> mergedAccounts(n);
        unordered_map<int, set<string>> parentToEmails;

        for (auto& [email, accIndex] : emailToAccount) {
            int parentIndex = ds.findUPar(accIndex);
            parentToEmails[parentIndex].insert(email);
        }

        // Step 3: Format the result
        vector<vector<string>> result;
        for (auto& [index, emails] : parentToEmails) {
            vector<string> acc;
            acc.push_back(accounts[index][0]); // name
            acc.insert(acc.end(), emails.begin(), emails.end()); // sorted emails
            result.push_back(acc);
        }

        return result;
    }
};
