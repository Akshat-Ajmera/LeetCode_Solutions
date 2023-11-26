class Solution {
private:
    bool valid(vector<vector<int>> &g, vector<vector<int>> &vis, int row, int col) {
        return !(row>=g.size() || row<0 || col>=g[0].size() || col<0 || !g[row][col] || vis[row][col]);
    }
    void bfs(vector<vector<int>> &g, vector<vector<int>> &vis, int r, int c, int m, int n) {
        queue<pair<int,int>> q;
        q.push({r,c});
        while(!q.empty()) {
            auto it = q.front();
            int row = it.first, col = it.second;
            g[row][col] = 0;
            q.pop();
            vector<int> drow = {0,-1,0,1}, dcol = {-1,0,1,0};
            for(int a=0; a<4; a++) {
                int nrow = row + drow[a];
                int ncol = col + dcol[a];
                if(valid(g,vis,nrow,ncol)) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& g) {
        int m = g.size(), n = g[0].size(), cnt = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            if(g[i][0]) {
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(g[i][n-1]) {
                q.push({i,n-1});
                vis[i][n-1];
            }
        }
        for(int j=0; j<n; j++) {
            if(g[0][j]) {
                q.push({0,j});
                vis[0][j];
            }
            if(g[m-1][j]) {
                q.push({m-1,j});
                vis[m-1][j];
            }
        }
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            bfs(g,vis,it.first,it.second,m,n);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                cnt += g[i][j];
            }
        }
        return cnt;
    }
};