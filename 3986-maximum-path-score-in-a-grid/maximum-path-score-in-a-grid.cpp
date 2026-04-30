class Solution {
private:
    int solve(vector<vector<int>>& grid, vector<vector<vector<int>>> &dp, int i, int j, int k) {
        if(i < 0 || j < 0 || k < 0) return -1e8;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        if(!i && !j) return 0;
        int a = solve(grid, dp, i - 1, j, k - (grid[i][j] ? 1 : 0)) + grid[i][j];
        int b = solve(grid, dp, i, j - 1, k - (grid[i][j] ? 1 : 0)) + grid[i][j];
        return dp[i][j][k] = max(a, b);
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans;
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (k+1, -1)));
        ans = solve(grid, dp, m-1, n-1, k);
        return (ans >= 0 ? ans : -1);
    }
};