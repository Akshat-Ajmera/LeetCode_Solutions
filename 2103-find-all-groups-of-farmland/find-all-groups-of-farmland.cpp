class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &land, vector<vector<bool>> &vis, vector<vector<int>> &ans) {
        int nrow = row, ncol = col, m = land.size(), n = land[0].size();
        while(nrow < m && land[nrow][col]) nrow++;
        nrow--;
        while(ncol < n && land[row][ncol]) ncol++;
        ncol--;
        ans.push_back({row, col, nrow, ncol});
        for(int drow = row; drow <= nrow; drow++) {
            for(int dcol = col; dcol <= ncol; dcol++) {
                vis[drow][dcol] = true;
            }
        }
        return;
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        vector<vector<bool>> vis(m, vector<bool> (n, false));
        vector<vector<int>> ans;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(vis[i][j] || !land[i][j]) continue;
                bfs(i, j, land, vis, ans);
            }
        }
        return ans;
    }
};