class Solution {
private:
    int solve(int n, vector<int> &nums, vector<int> &dp) {
        if(n >= nums.size()) return 1e9;
        if(n == nums.size()-1) return 0;
        if(dp[n] != -1) return dp[n];
        int j = nums[n], ans = 1e9;
        for(int i=1; i<=j; i++) {
            ans = min(ans, 1 + solve(n+i, nums, dp));
        }
        return dp[n] = ans;
    }
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};