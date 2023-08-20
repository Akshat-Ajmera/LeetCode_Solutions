class Solution {
private:
    int solve(vector<int> &c, vector<vector<int>> &dp, int n, int m) {
        if(!n) {
            return ((m % c[n]) == 0);
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        int notTake = solve(c,dp,n-1,m), Take = 0;
        if(m >= c[n]) {
            Take = solve(c,dp,n,m-c[n]);
        }
        return dp[n][m] = notTake + Take;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(coins,dp,n-1,amount);
    }
};