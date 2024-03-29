class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &vis) {
        for(auto &adjNode : adj[node]) {
            if(vis[adjNode]) continue;
            vis[adjNode] = true;
            dfs(adjNode, adj, vis);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        vis[0] = true;
        dfs(0, rooms, vis);
        for(bool it : vis) {
            if(!it) return false;
        }
        return true;
    }
};