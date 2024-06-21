class Solution {
private:    
    int solve(string &s1, string &s2, int m, int n, vector<vector<int>> &dp) {
        if(m < 0 || n < 0) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int ans = 0, a = 0, b = 0;
        if(s1[m] == s2[n]) ans = 1 + solve(s1, s2, m-1, n-1, dp);
        else {
            a = solve(s1, s2, m-1, n, dp);
            b = solve(s1, s2, m, n-1, dp);
            ans = max(a, b);
        }
        return dp[m][n] = ans;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(text1, text2, m-1, n-1, dp);
    }
};