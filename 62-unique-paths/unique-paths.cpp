class Solution {
private:
    int solve(int m, int n, vector<vector<int>> &dp) {
        if(m<0 || n<0) {
            return 0;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(!m && !n) {
            return dp[0][0] = 1;
        }
        return dp[m][n] = solve(m-1,n,dp) + solve(m,n-1,dp);
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,dp);
    }
};