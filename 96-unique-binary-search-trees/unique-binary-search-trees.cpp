class Solution {
private:
    int solve(int n, vector<int> &dp) {
        if(dp[n] != -1) return dp[n];
        if(n == 0 || n == 1) return dp[n] = 1;
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += solve(i, dp) * solve(n-i-1, dp);
        }
        return dp[n] = ans;
    }
public:
    int numTrees(int n) {
        vector<int> dp(n+1, -1);
        return solve(n, dp);
    }
};