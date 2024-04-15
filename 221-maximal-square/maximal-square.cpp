class Solution {
private:
    int solve(int m, int n, vector<vector<char>> &v, int &ans, vector<vector<int>> &dp) {
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        if(v[m][n] == '0') return dp[m][n] = 0;
        int a = 0, b = 0, c = 0;
        if(m >= 1) a = solve(m-1, n, v, ans, dp);
        if(n >= 1) b = solve(m, n-1, v, ans, dp);
        if(m >= 1 && n >= 1) c = solve(m-1, n-1, v, ans, dp);
        ans = max(ans, 1 + min({a, b, c}));
        return dp[m][n] = 1 + min({a, b, c});
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<vector<int>> dp(m, vector<int> (n, -1)); 
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                solve(i, j, matrix, ans, dp);
            }
        }
        return ans * ans;
    }
};