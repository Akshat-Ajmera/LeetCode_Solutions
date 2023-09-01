class Solution {
private:
    const int mod = 1e9+7;
private:
    long long solve(vector<vector<int>> &g, vector<vector<vector<long long>>> &dp, int k, int i, int j, int sum) {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size()) {
            return 0;
        }
        sum += g[i][j];
        if(dp[i][j][sum%k] != -1) {
            return dp[i][j][sum%k];
        }
        if(i==g.size()-1 && j==g[0].size()-1) {
            return dp[i][j][sum%k] = (!(sum%k));
        }
        long long a = solve(g,dp,k,i+1,j,sum) % mod;
        long long b = solve(g,dp,k,i,j+1,sum) % mod;
        return dp[i][j][sum%k] = (a+b)%mod;
    }

public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        long long m=grid.size(), n=grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>> (n, vector<long long> (k, -1)));
        return solve(grid,dp,k,0,0,0)%mod;
    }
};