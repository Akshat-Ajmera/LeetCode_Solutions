class Solution {
private:
    int solve(vector<int> &p, vector<vector<int>> &dp, int n, int b) {
        if(n==p.size()) {
            return 0;
        }
        if(dp[n][b] != -1) {
            return dp[n][b];
        }
        int profit = 0;
        if(b==1) {
            profit = max(-p[n]+solve(p,dp,n+1,0), solve(p,dp,n+1,1));
        }
        else {
            profit = max(p[n]+solve(p,dp,n+1,1), solve(p,dp,n+1,0));
        }
        return dp[n][b] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(0,solve(prices,dp,0,1));
    }
};