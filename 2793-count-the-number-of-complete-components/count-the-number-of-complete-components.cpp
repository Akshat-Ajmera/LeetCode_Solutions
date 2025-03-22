class Solution {
private:
    int solve(vector<vector<int>> &adj, vector<bool> &vis, int i) {
        vis[i] = true;
        int num = 0, siz;
        set<int> st;
        queue<int> que;
        que.push(i);
        while(!que.empty()) {
            auto node = que.front();
            que.pop();
            for(auto adjNode : adj[node]) {
                if(vis[adjNode]) continue;
                que.push(adjNode);
                st.insert(adjNode);
                vis[adjNode] = true;
            }
        }
        siz = st.size();
        for(auto &it : st) {
            if(adj[it].size() != siz) {
                return 0;
            }
        }
        return 1;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<n; i++) {
            if(!vis[i]) ans += solve(adj, vis, i);
        }
        return ans;
    }
};