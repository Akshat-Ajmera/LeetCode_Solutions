class Solution {
private:
    int solve(vector<int> &nums, vector<int> &dp, int n) {
        if(n<0) {
            return 0;
        }
        if(dp[n] != INT_MIN) {
            return dp[n];
        }
        if(!n) {
            return dp[n] = nums[n];
        }
        int p = nums[n] + solve(nums,dp,n-2);
        int np = solve(nums,dp,n-1);
        return dp[n] = max(p,np);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,INT_MIN);
        return solve(nums,dp,n-1);
    }
};