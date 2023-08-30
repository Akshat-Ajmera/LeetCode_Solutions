class Solution {
private:
    int solve(vector<int> &v, vector<vector<int>> &dp, int ind, int prev) {
        if(ind == v.size()) {
            return 0;
        }
        if(dp[ind][prev+1] != -1) {
            return dp[ind][prev+1];
        }
        int nottake = solve(v,dp,ind+1,prev), take = 0;
        if(prev == -1 || v[prev] < v[ind]) {
            take = 1 + solve(v,dp,ind+1,ind);
        }
        return dp[ind][prev+1] = max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(nums,dp,0,-1);
    }
};