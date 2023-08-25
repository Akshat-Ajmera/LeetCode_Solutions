class Solution {
private:
    int solve(vector<int> &p, vector<vector<vector<int>>> &dp, int i, int b, int c) {
        if(i==p.size() || !c) {
            return 0;
        }
        if(dp[i][b][c] != -1) {
            return dp[i][b][c];
        }
        if(b) {
            return dp[i][b][c] = max(-p[i] + solve(p,dp,i+1,0,c), solve(p,dp,i+1,1,c));
        }
        else {
            return dp[i][b][c] = max(p[i] + solve(p,dp,i+1,1,c-1), solve(p,dp,i+1,0,c));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        return max(0,solve(prices,dp,0,1,2));
    }
};