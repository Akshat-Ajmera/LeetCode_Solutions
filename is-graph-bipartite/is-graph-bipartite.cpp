class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;
        for(int i=0; i<n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                q.push(i);
                while(!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for(auto it : graph[node]) {
                        if(color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        }
                        else {
                            if(color[it] == color[node]) {
                                return false;
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    void bfs(int src, int n, vector<bool> &vis, vector<int> &color, int &flag, vector<vector<int>> &graph) {
        vis[src] = true;
        queue<int> q;
        q.push(src);
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(auto i=graph[node].begin(); i<graph[node].end(); i++) {
                if(!vis[*i]) {
                    color[*i] = !color[node];
                    q.push(*i);
                }
                else {
                    if(color[*i] == color[node]) {
                        flag = 0;
                    }
                }
            }
            if(!flag) {
                break;
            }
        }
    }
public:
    bool isBipartite(vector<vector<int>> &graph) {
        int n = graph.size();
        int flag = 1;
        vector<int> adj[n];
        vector<bool> vis(n, false);
        vector<int> color(n, -1);
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                color[i] = 0;
                bfs(i, n, vis, color, flag, graph);
                if(!flag) {
                    return false;
                }
            }
        }
        return true;
    }
};
*/