class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i] = i;
        }
    }
    int findUltPar(int node) {
        if(parent[node] == node) {
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int num = edges.size();
        sort(edges.rbegin(), edges.rend());
        DisjointSet ds_r(n), ds_g(n);
        bool r_f = false, g_f = false;
        int r_edge = 0, g_edge = 0, b_edge = 0, r_comp = 0, g_comp = 0;
        for(auto it : edges) {
            int type = it[0], u = it[1], v = it[2];
            if(type == 1) {
                if(ds_r.findUltPar(u) != ds_r.findUltPar(v)) {
                    ds_r.unionBySize(u,v);
                    r_edge++;
                }            
            }
            else if(type == 2) {
                if(ds_g.findUltPar(u) != ds_g.findUltPar(v)) {
                    ds_g.unionBySize(u,v);
                    g_edge++;
                }
            }
            else {
                if(ds_r.findUltPar(u) != ds_r.findUltPar(v)) {
                    ds_r.unionBySize(u,v);
                    r_f = true;
                }
                if(ds_g.findUltPar(u) != ds_g.findUltPar(v)) {
                    ds_g.unionBySize(u,v);
                    g_f = true;
                }
                if(r_f || g_f) {
                    b_edge++;
                }
                r_f = false;
                g_f = false;
            }
        }
        for(int i=1; i<=n; i++) {
            if(ds_r.parent[i] == i) {
                r_comp++;
            }
            if(ds_g.parent[i] == i) {
                g_comp++;
            }
        }
        if(r_comp > 1 || g_comp > 1) {
            return -1;
        }
        return num - (r_edge + g_edge + b_edge);
    }
};