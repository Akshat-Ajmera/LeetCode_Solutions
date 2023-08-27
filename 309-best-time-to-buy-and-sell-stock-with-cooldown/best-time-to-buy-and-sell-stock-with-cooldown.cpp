class Solution {
private:
    int solve(vector<int> &p, vector<vector<int>> &dp, int i, int b) {
        if(i>=p.size()) {
            return 0;
        }
        if(dp[i][b] != -1) {
            return dp[i][b];
        }
        if(b) {
            return dp[i][b] = max(-p[i]+solve(p,dp,i+1,0), solve(p,dp,i+1,1));
        }
        else {
            return dp[i][b] = max(p[i]+solve(p,dp,i+2,1), solve(p,dp,i+1,0));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return solve(prices,dp,0,1);
    }
};