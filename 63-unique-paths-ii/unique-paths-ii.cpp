class Solution {
private:
    int solve(vector<vector<int>> &g, vector<vector<int>> &dp, int m, int n) {
        if(m<0 || n<0) {
            return 0;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(!m && !n) {
            return dp[0][0] = 1;
        }
        if(g[m][n]) {
            return 0;
        }
        return dp[m][n] = solve(g,dp,m-1,n) + solve(g,dp,m,n-1);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(obstacleGrid,dp,m-1,n-1);
    }
};