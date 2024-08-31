class Solution {
private:
    int solve(vector<vector<int>> &adj, int node, string &s, int &ans) {
        int mxm1 = 0, mxm2 = 0;
        for(auto &it : adj[node]) {
            int val = solve(adj, it, s, ans);
            if(s[it] != s[node]) {
                if(val > mxm1) {
                    mxm2 = mxm1;
                    mxm1 = val;
                }
                else if(val > mxm2) {
                    mxm2 = val;
                }
            }
        }
        ans = max(ans, 1 + mxm1 + mxm2);
        return max(1, 1 + mxm1);
    }
public:
    int longestPath(vector<int> &par, string s) {
        int n = par.size(), ans = 0;
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++) {
            if(par[i] == -1) continue;
            adj[par[i]].push_back(i);
        }
        solve(adj, 0, s, ans);
        return ans;
    }
};