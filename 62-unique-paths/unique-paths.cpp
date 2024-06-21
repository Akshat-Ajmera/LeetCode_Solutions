class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp) {
        if(dp[m][n] != -1) return dp[m][n];
        if(!m && !n) return dp[m][n] = 1;
        int a = 0, b = 0;
        if(m > 0) a = solve(m-1, n, dp);
        if(n > 0) b = solve(m, n-1, dp);
        return dp[m][n] = (a + b);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, dp);
    }
};