class Solution {
private:
    int dfs(vector<vector<int>> &g, vector<int> &quiet, vector<int> &ans, int node) {
        if(ans[node] != -1) return ans[node];
        int res = node;
        for(auto it : g[node]) {
            int d = dfs(g, quiet, ans, it);
            if(quiet[res] > quiet[d]) res = d;
        }
        return res;
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size(), curr;
        vector<int> ans(n, -1);
        vector<vector<int>> g(n);
        for(auto it : richer) g[it[1]].push_back(it[0]);
        for(int i=0; i<n; i++) {
            if(ans[i] == -1) ans[i] = dfs(g, quiet, ans, i);
        }
        return ans;
    }
};