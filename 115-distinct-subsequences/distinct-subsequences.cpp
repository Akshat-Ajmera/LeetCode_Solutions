class Solution {
private:
    int solve(string s, string t, vector<vector<int>> &dp, int n, int m) {
        if(m<0) {
            return 1;
        }
        if(n<0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s[n]==t[m]) {
            return dp[n][m] = solve(s,t,dp,n-1,m-1) + solve(s,t,dp,n-1,m);
        }
        else {
            return dp[n][m] = solve(s,t,dp,n-1,m);
        }
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(s,t,dp,n-1,m-1);
    }
};