class Solution {
private:
    bool solve(string s, string t, vector<vector<int>> &dp, int n, int m) {
        if(m<0 && n<0) {
            return true;
        }
        if(m<0 && n>=0) {
            return false;
        }
        if(n<0 && m>=0) {
            for(int i=m; i>=0; i--) {
                if(t[i] != '*') {
                    return false;
                }
            }
            return true;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s[n]==t[m] || t[m]=='?') {
            return dp[n][m] = solve(s,t,dp,n-1,m-1);
        }
        if(t[m]=='*') {
            return dp[n][m] = (solve(s,t,dp,n,m-1) || solve(s,t,dp,n-1,m)); 
        }
        return dp[n][m] = false;
    }
public:
    bool isMatch(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<bool>> dp(n+1, vector<bool> (m+1, 0));
        // return solve(s,t,dp,n-1,m-1);
        dp[0][0] = 1;
        for(int j=1; j<=m; j++) {
            bool flag = true;
            for(int i=1; i<=j; i++) {
                if(t[i-1] != '*') {
                    flag = false;
                }
            }
            dp[0][j] = flag;
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s[i-1]==t[j-1] || t[j-1]=='?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(t[j-1]=='*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};