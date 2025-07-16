class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUPar(parent[node]);
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables

        DisjointSet ds(n);
        int extraEdges = 0;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            if (ds.findUPar(u) == ds.findUPar(v)) {
                extraEdges++; // cycle edge
            } else {
                ds.unionBySize(u, v);
            }
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findUPar(i) == i) components++;
        }

        int needed = components - 1;
        return (extraEdges >= needed) ? needed : -1;
    }
};
