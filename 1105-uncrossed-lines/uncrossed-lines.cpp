class Solution {
private:
    int solve(vector<int> &v, vector<int> &u, int n, int m, vector<vector<int>> &dp) {
        if(n < 0 || m < 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        int a = solve(v, u, n-1, m, dp), b = solve(v, u, n, m-1, dp), c = 0;
        if(v[n] == u[m]) c = 1 + solve(v, u, n-1, m-1, dp);
        return dp[n][m] = max({a, b, c});
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(nums1, nums2, n-1, m-1, dp);
    }
};