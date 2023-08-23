class Solution {
private:
    int solve(string s1, string s2, vector<vector<int>> &dp, int n, int m) {
        if(n<0 || m<0) {
            return 0;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s1[n]==s2[m]) {
            return dp[n][m] = 1 + solve(s1,s2,dp,n-1,m-1);
        }
        else {
            return dp[n][m] = max(solve(s1,s2,dp,n-1,m),solve(s1,s2,dp,n,m-1));
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return m + n - 2*solve(word1,word2,dp,n-1,m-1);
    }
};