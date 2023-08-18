class Solution {
private:
    int solve(vector<vector<int>> &g, vector<vector<vector<int>>> &dp, int i, int j1, int j2, int m, int n) {
        if(j1<0 || j2<0 || j1>=n || j2>=n || i>=m) {
            return INT_MIN;
        }
        if(dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        if(i == m-1) {
            if(j1==j2) {
                return dp[i][j1][j2] = g[i][j1];
            }
            else {
                return dp[i][j1][j2] = g[i][j1] + g[i][j2];
            }
        }
        int mxm = INT_MIN;
        for(int d1=-1; d1<=1; d1++) {
            for(int d2=-1; d2<=1; d2++) {
                mxm = max(mxm,solve(g,dp,i+1,j1+d1,j2+d2,m,n));
            }
        }
        if(j1==j2) {
            return dp[i][j1][j2] = g[i][j1] + mxm;
        }
        return dp[i][j1][j2] = g[i][j1] + g[i][j2] + mxm;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1)));
        return solve(grid,dp,0,0,n-1,m,n);
    }
};