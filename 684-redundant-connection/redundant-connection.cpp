class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    int findUltPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUltPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int up_u = findUltPar(u), up_v = findUltPar(v);
        if(up_u == up_v) {
            return;
        }
        if(size[up_u] > size[up_v]) {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];   
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), u, v, a, b;
        DisjointSet ds(n);
        for(auto it : edges) {
            u = it[0];
            v = it[1];
            if(ds.findUltPar(u) != ds.findUltPar(v)) {
                ds.unionBySize(u, v);
            }
            else {
                a = u;
                b = v;
            }
        }
        return {a, b};
    }
};