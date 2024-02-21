class Solution {
private:
    int solve(vector<vector<int>> &v, int m, int n, vector<vector<int>> &dp) {
        if(dp[m][n] != -1) return dp[m][n];
        if(!m && !n) return dp[m][n] = v[m][n];
        int a = INT_MAX, b = INT_MAX;
        if(m>=1) a = v[m][n] + solve(v, m-1, n, dp);
        if(n>=1) b = v[m][n] + solve(v, m, n-1, dp);
        return dp[m][n] = min(a, b);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(grid, m-1, n-1, dp);
    }
};