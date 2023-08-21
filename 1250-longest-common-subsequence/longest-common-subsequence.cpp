class Solution {
private:
    int solve(string &s1, string &s2, vector<vector<int>> &dp, int m, int n) {
        if(m<0 || n<0) {
            return 0;
        }
        if(dp[m][n] != -1) {
            return dp[m][n];
        }
        if(s1[m]==s2[n]) {
            return dp[m][n] = 1 + solve(s1,s2,dp,m-1,n-1);
        }
        return dp[m][n] = max(solve(s1,s2,dp,m-1,n),solve(s1,s2,dp,m,n-1)); 
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(text1, text2, dp, m-1, n-1);
    }
};