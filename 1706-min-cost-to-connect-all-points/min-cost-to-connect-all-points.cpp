class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> &pts) {
        int n = pts.size(), ans = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int dis = abs(pts[i][0] - pts[j][0]) + abs(pts[i][1] - pts[j][1]);
                adj[i].push_back({j, dis});
                adj[j].push_back({i, dis});
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0, 0});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int wt = it.first, node = it.second;
            if(vis[node]) continue;
            ans += wt;
            vis[node] = true;
            for(auto &it1 : adj[node]) {
                if(!vis[it1.first]) pq.push({it1.second, it1.first});
            }
        }
        return ans;
    }
};
