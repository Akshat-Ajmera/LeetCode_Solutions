    class Solution {
    private:
        long long solve(int i, int j, int k, vector<int> &prices, vector<vector<vector<long long>>> &dp) {
            if(i == prices.size()) return !j ? 0 : INT_MIN;
            if(!k) return 0;
            if(dp[i][j][k] != -1) return dp[i][j][k];
            long long ans = 0;
            if(!j) ans = max({solve(i+1, 0, k, prices, dp), solve(i+1, 1, k, prices, dp) - prices[i], solve(i+1, 2, k, prices, dp) + prices[i]});
            else if(j == 1) ans = max(solve(i+1, 1, k, prices, dp), solve(i+1, 0, k-1, prices, dp) + prices[i]);
            else ans = max(solve(i+1, 2, k, prices, dp), solve(i+1, 0, k-1, prices, dp) - prices[i]);
            return dp[i][j][k] = ans;
        }
    public:
        long long maximumProfit(vector<int>& prices, int k) {
            vector<vector<vector<long long>>> dp(prices.size(), vector<vector<long long>> (3, vector<long long> (k+1, -1)));
            return solve(0, 0, k, prices, dp);
        }
    };