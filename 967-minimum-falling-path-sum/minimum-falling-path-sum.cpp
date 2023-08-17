class Solution {
private:
    int solve(vector<vector<int>> &g, vector<vector<int>> &dp, int m, int n) {
        if(m<0 || n<0 || m>=g.size() || n>=g.size()) {
            return INT_MAX;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(!m) {
            return dp[m][n] = g[m][n];
        }
        return dp[m][n] = g[m][n] + min({solve(g,dp,m-1,n-1),solve(g,dp,m-1,n),solve(g,dp,m-1,n+1)});
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size(), mn = INT_MAX, res;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        // for(int i=0; i<n; i++) {
        //     res = solve(matrix,dp,n-1,i);
        //     if(mn > res) {
        //         mn = res;
        //     }
        // }
        for(int i=0; i<n; i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i=1; i<n; i++) {
            for(int j=0; j<n; j++) {
                dp[i][j] = matrix[i][j] + min({dp[i-1][max(j-1,0)],dp[i-1][j],dp[i-1][min(j+1,n-1)]});
            }
        }
        for(int i=0; i<n; i++) {
            if(mn > dp[n-1][i]) {
                mn = dp[n-1][i];
            }
        }
        return mn;
    }
};