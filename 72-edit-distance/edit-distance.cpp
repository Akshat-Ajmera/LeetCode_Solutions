class Solution {
private:
    int solve(string s1, string s2, vector<vector<int>> &dp, int n, int m) {
        if(n<0) {
            return m+1;
        }
        if(m<0) {
            return n+1;
        }
        if(dp[n][m] != -1) {
            return dp[n][m];
        }
        if(s1[n]==s2[m]) {
            return dp[n][m] = solve(s1,s2,dp,n-1,m-1);
        }
        else {
            int a = 1 + solve(s1,s2,dp,n,m-1);
            int b = 1 + solve(s1,s2,dp,n-1,m);
            int c = 1 + solve(s1,s2,dp,n-1,m-1);
            return dp[n][m] = min({a,b,c});
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(word1,word2,dp,n-1,m-1);
    }
};