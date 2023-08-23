class Solution {
private:
    int solve(vector<vector<int>> &g, vector<vector<vector<int>>> &dp, int i1, int j1, int i2) {
        int j2 = i1 + j1 - i2, n = g.size();
        if(i1>=n || j1>=n || i2>=n || j2>=n || g[i1][j1]==-1 || g[i2][j2]==-1) {
            return INT_MIN;
        }
        if(dp[i1][j1][i2] != -1) {
            return dp[i1][j1][i2];
        }
        if(i1==n-1 && j1==n-1) {
            return dp[n-1][n-1][n-1] = g[n-1][n-1];
        }
        int ans = g[i1][j1];
        if(i1 != i2) {
            ans += g[i2][j2];
        }
        int a = solve(g,dp,i1+1,j1,i2+1);
        int b = solve(g,dp,i1,j1+1,i2+1);
        int c = solve(g,dp,i1+1,j1,i2);
        int d = solve(g,dp,i1,j1+1,i2);
        return dp[i1][j1][i2] = ans + max({a,b,c,d});

    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == -1 || grid[n-1][n-1] == -1) {
            return 0;
        }
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (n, -1)));
        return max(0,solve(grid,dp,0,0,0));
    }
};