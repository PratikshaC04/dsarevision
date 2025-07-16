class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // path compression
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1); // total virtual nodes
        unordered_map<int, int> nodesUsed;

        for (auto& stone : stones) {
            int row = stone[0];
            int col = stone[1] + maxRow + 1; // offset cols
            ds.unionBySize(row, col);
            nodesUsed[row] = 1;
            nodesUsed[col] = 1;
        }

        int components = 0;
        for (auto& [node, _] : nodesUsed) {
            if (ds.findUPar(node) == node) {
                components++;
            }
        }

        return stones.size() - components;
    }
};
