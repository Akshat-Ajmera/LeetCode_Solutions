class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) par[i] = i;
    }
    int findUltPar(int node) {
        if(par[node] == node) return node;
        else return par[node] = findUltPar(par[node]);
    }
    int join(int u, int v) {
        int ultParU = findUltPar(u), ultParV = findUltPar(v);
        if(ultParU == ultParV) return ultParU;
        if(size[ultParU] >= size[ultParV]) {
            par[ultParV] = ultParU;
            size[ultParU] += size[ultParV];
            return ultParU;
        }
        else {
            par[ultParU] = ultParV;
            size[ultParV] += size[ultParU];
            return ultParV;
        }
    }
};

class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet obj(n);
        vector<int> andOp(n, INT_MAX), answer;
        for(auto &it : edges) {
            andOp[obj.join(it[0], it[1])] &= it[2];
        }
        for(int i=0; i<n; i++) andOp[obj.findUltPar(i)] &= andOp[i];
        for(auto &it : query) {
            if(obj.findUltPar(it[0]) == obj.findUltPar(it[1])) answer.push_back(andOp[obj.findUltPar(it[0])]);
            else answer.push_back(-1);
        }
        return answer;
    }
};