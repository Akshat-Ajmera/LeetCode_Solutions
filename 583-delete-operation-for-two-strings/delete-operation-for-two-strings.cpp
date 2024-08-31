class Solution {
private:
    int solve(string &s1, string &s2, int n1, int n2, vector<vector<int>> &dp) {
        if(n1 < 0 && n2 < 0) return 0;
        if(n1 < 0) return n2 + 1;
        if(n2 < 0) return n1 + 1;
        if(dp[n1][n2] != -1) return dp[n1][n2];
        int ans;
        if(s1[n1] == s2[n2]) ans = solve(s1, s2, n1-1, n2-1, dp);
        else ans = 1 + min(solve(s1, s2, n1-1, n2, dp), solve(s1, s2, n1, n2-1, dp));
        return dp[n1][n2] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        vector<vector<int>> dp(n1, vector<int> (n2, -1));
        return solve(word1, word2, n1-1, n2-1, dp);
    }
};