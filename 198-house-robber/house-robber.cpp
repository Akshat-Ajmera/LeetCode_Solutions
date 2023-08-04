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
        int n = nums.size(), p=0, np=0, slast=0, last=0, ans=0;
        if(n==1) {
            return nums[0];
        }
        // vector<int> dp(n,-1);
        // return solve(nums,dp,n-1);
        slast = nums[0];
        last = max(nums[0],nums[1]);
        ans = max(slast,last);
        for(int i=2; i<n; i++) {
            p = nums[i] + slast;
            np = last;
            ans = max(p,np);
            slast = last;
            last = ans;
        }
        return ans;
    }
};