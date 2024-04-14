class Solution {
private:
    const int mod = 1e9 + 7;
    // long long solve(int k, int n, vector<vector<long long>> &dp) {
    //     if(dp[n][k] != -1) return dp[n][k];
    //     if(!k) return 1;
    //     if(!n) return !k;
    //     if(k > n) return 0;
    //     long long ans = 0;
    //     for(int j=n-1; j>=0; j--) {
    //         ans = ((ans % mod) + (((n - j) % mod) * (solve(k-1, j, dp) % mod)) % mod) % mod;
    //     }
    //     return dp[n][k] = ans;
    // }
    int solve(int k, int n, vector<vector<int>> &dp) {
        if(dp[n][k] != -1) return dp[n][k];
        if(!k) return 1;
        if(!n) return !k;
        if(k > n) return 0;
        int ans = solve(k, n-1, dp);
        for(int i=1; i<=n; i++){
            ans = (ans % mod + solve(k-1, n-i, dp) % mod) % mod;
        }
        return dp[n][k] = ans;
    }
public:
    int numberOfSets(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int> (k+1, -1));
        return solve(k, n-1, dp);
    }
};
