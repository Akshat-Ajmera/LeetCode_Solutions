class Solution {
public:
    int maximumLength(vector<int>& v, int k) {
        int n = v.size(), ans = 0, mxm = 0, mod;
        vector<vector<int>> dp(n, vector<int> (k, 1));
        for(int i=1; i<n; i++) {
             for(int j=0; j<i; j++) {
                mod = (v[i] + v[j]) % k;
                dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
                ans = max(ans, dp[i][mod]);
             }
        }
        return ans;
    }
};