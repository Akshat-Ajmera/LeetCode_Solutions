class Solution {
private:
    int solve(int m, int n, string &s1, string &s2, vector<vector<int>> &dp) {
        if(m < 0) return n+1;
        if(n < 0) return m+1;
        if(dp[m][n] != -1) return dp[m][n];
        int ans = 0, a = 0, b = 0, c = 0;
        if(s1[m] == s2[n]) {
            ans = solve(m-1, n-1, s1, s2, dp);
        }
        else {
            a = solve(m-1, n, s1, s2, dp);
            b = solve(m, n-1, s1, s2, dp);
            c = solve(m-1, n-1, s1, s2, dp);
            ans = 1 + min({a, b, c});
        }
        return dp[m][n] = ans;
    }
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, word1, word2, dp);
    }
};