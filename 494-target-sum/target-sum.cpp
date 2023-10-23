class Solution {
private:
    int solve(vector<int> &v, vector<vector<int>> &dp, int k, int n) {
        if(!n) {
            if(!v[n] && !k) {
                return dp[n][k] = 2;
            }
            if(!k || v[n]==k) {
                return dp[n][k] = 1;
            }
            return dp[n][k] = 0;
        }
        int a = solve(v,dp,k,n-1), b = 0;
        if(k >= v[n]) {
            b = solve(v,dp,k-v[n],n-1);
        }
        return dp[n][k] = (a + b);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = accumulate(nums.begin(),nums.end(),0);
        int k1 = sum-target, k2 = sum+target;
        // if(k1%2 || k1<0) {
        //     return 0;
        // }
        // k1 /= 2;
        // vector<vector<int>> dp(n, vector<int> (k1+1, -1));
        // return solve(nums,dp,k1,n-1);
        if(k2%2 || k2<0) {
            return 0;
        }
        k2 /= 2;
        vector<vector<int>> dp(n, vector<int> (k2+1, -1));
        return solve(nums,dp,k2,n-1);
    }
};