class Solution {
private:
    bool check(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        return !(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || !grid[row][col] || vis[row][col]);
    }
    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis) {
        int ans = 0;
        int drow[4] = {0, -1, 0, 1}, dcol[4] = {-1, 0, 1, 0};
        vis[i][j] = true;
        queue<pair<int, int>> que;
        que.push({i, j});
        while(!que.empty()) {
            auto it = que.front();
            que.pop();
            int row = it.first, col = it.second;
            ans++;
            for(int a=0; a<4; a++) {
                int nrow = row + drow[a], ncol = col + dcol[a];
                if(!check(nrow, ncol, grid, vis)) continue;
                que.push({nrow, ncol});
                vis[nrow][ncol] = true;
            }
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] && !vis[i][j]) ans = max(ans, bfs(i, j, grid, vis));
            }
        }
        return ans;
    }
};