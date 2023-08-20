class Solution {
private:
    int solve(vector<int> &c, vector<vector<int>> &dp, int t, int n) {
        if(!n) {
            if(!(t%c[n])) {
                return t/c[n];
            }
            else {
                return 1e9;
            }
        }
        if(dp[n][t] != -1) {
            return dp[n][t];
        }
        int notTake = solve(c,dp,t,n-1), take = INT_MAX;
        if(t >= c[n]) {
            take = 1 + solve(c,dp,t-c[n],n);
        }
        return dp[n][t] = min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins,dp,amount,n-1);
        if(ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};