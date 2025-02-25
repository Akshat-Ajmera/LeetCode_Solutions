class Solution {
private:
    void dfs0(int node, vector<vector<int>>& adj, vector<int> &path, vector<int> &final, vector<bool> &vis, int bob) {
        if(final.size()) return;
        path.push_back(node);
        vis[node] = true;
        if(node == bob) {
            final = path;
            return;
        }
        for(int adjNode : adj[node]) {
            if(vis[adjNode]) continue;
            dfs0(adjNode, adj, path, final, vis, bob);
        }
        path.pop_back();
        return;
    }
    void dfs1(int node, int tot, int &ans, int t, unordered_map<int, int> &mp, vector<bool> &vis, vector<int> &amt, vector<int> &path, vector<vector<int>> &adj) {
        int temp = 0;
        if(mp.find(node) == mp.end() || t < mp[node]) tot += amt[node];
        else if(mp[node] == t) tot += (amt[node] / 2);
        vis[node] = true;
        if(node && adj[node].size() == 1) {
            ans = max(ans, tot);
            return;
        }
        for(auto adjNode : adj[node]) {
            if(vis[adjNode]) continue;
            dfs1(adjNode, tot, ans, t + 1, mp, vis, amt, path, adj);
        }
        return;
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amt) {
        int n = edges.size() + 1, ans = INT_MIN;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> path, final;
        unordered_map<int, int> mp;
        dfs0(0, adj, path, final, vis, bob);
        reverse(final.begin(), final.end());
        for(int i=0; i<final.size(); i++) mp[final[i]] = i;
        fill(vis.begin(), vis.end(), false);
        dfs1(0, 0, ans, 0, mp, vis, amt, final, adj);
        return ans;
    }
};