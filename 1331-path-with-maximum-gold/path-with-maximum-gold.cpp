class Solution {
private:
    bool check(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col) {
        return !(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || vis[row][col] || !grid[row][col]);
    }
    int solve(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col) {
        int ans = 0;
        vis[row][col] = 1;
        int drow[4] = {0, -1, 0, 1}, dcol[4] = {-1, 0, 1, 0};
        for(int i=0; i<4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if(!check(grid, vis, nrow, ncol)) continue;
            ans = max(ans, solve(grid, vis, nrow, ncol));
        }
        ans += grid[row][col];
        vis[row][col] = 0;
        return ans;
    }
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> vis(m, vector<int> (n, 0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!grid[i][j]) continue;
                ans = max(ans, solve(grid, vis, i, j));
            }
        }
        return ans;
    }
};