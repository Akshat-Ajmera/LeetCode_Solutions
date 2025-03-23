class Solution {
private:
    int mod = 1e9 + 7;
    int dijkstra(vector<vector<pair<int, long long >>> &adj) {
        int n = adj.size();
        vector<long long> dis(n, LLONG_MAX), ways(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long dist = it.first, node = it.second;
            for(auto &adjNode : adj[node]) {
                if(adjNode.second + dist == dis[adjNode.first]) ways[adjNode.first] = ((ways[adjNode.first] % mod) + (ways[node] % mod) % mod);
                else if(adjNode.second + dist < dis[adjNode.first]) {
                    dis[adjNode.first] = adjNode.second + dist;
                    ways[adjNode.first] = ways[node] % mod;
                    pq.push({dis[adjNode.first], adjNode.first});
                }
            }
        }
        return ways[n-1] % mod;
    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, long long>>> adj(n);
        for(auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        return dijkstra(adj);
    }
};