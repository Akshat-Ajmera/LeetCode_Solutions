class Solution {
// private:
//     int solve(vector<int> &nums, vector<int> &dp, int n) {
//         if(n<0) {
//             return 0;
//         }
//         if(dp[n] != INT_MIN) {
//             return dp[n];
//         }
//         if(!n) {
//             return dp[n] = nums[n];
//         }
//         int p = nums[n] + solve(nums,dp,n-2);
//         int np = solve(nums,dp,n-1);
//         return dp[n] = max(p,np);
//     }
public:
    int rob(vector<int>& nums) {
        int n = nums.size(), p, np;
        if(n==1) {
            return nums[0];
        }
        vector<int> dp(n,-1);
        // return solve(nums,dp,n-1);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2; i<n; i++) {
            p = nums[i] + dp[i-2];
            np = dp[i-1];
            dp[i] = max(p,np);
        }
        return dp[n-1];
    }
};