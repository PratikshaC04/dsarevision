#include <vector>
using namespace std;

class Solution {
private:
    // DFS traversal function
    void dfs(int node, vector<vector<int>>& adjLs, vector<int>& vis) {
        vis[node] = 1;
        for (auto it : adjLs[node]) {
            if (!vis[it]) {
                dfs(it, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<vector<int>> adjLs(V);

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<int> vis(V, 0);
        int cnt = 0;

        // Count the number of connected components (provinces)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adjLs, vis);
            }
        }

        return cnt;
    }
};

