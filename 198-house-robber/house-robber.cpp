class Solution {
private:
    int solve(int n, vector<vector<int>>& dp, int prev, vector<int> &v) {
        if(n >= v.size()) {
            return 0;
        }
        if(dp[n][prev+1] != -1) {
            return dp[n][prev+1];
        }
        int notTake = solve(n+1,dp,prev,v), take = 0;
        if(prev == -1 || prev != n-1) {
            take = v[n] + solve(n+1,dp,n,v);
        }
        return dp[n][prev+1] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0,dp,-1,nums);
        return 0;
    }
};