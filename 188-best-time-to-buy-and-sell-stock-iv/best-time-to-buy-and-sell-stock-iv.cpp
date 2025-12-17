class Solution {
private:
    int solve(int i, int k, vector<int> &prices, vector<vector<int>> &dp) {
        if(i == prices.size() || !k) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int bought = 0, notBought = solve(i + 1, k, prices, dp);
        for(int j=i+1; j<prices.size(); j++) {
            bought = max(bought, prices[j] - prices[i] + solve(j+1, k-1, prices, dp));
        }
        return dp[i][k] = max(bought, notBought);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int> (k+1, -1));
        return solve(0, k, prices, dp);
    }
};