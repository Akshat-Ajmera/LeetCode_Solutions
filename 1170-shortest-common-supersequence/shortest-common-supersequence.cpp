class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            } 
        }
        string ans = "";
        int p = m, q = n;
        while(p>0 && q>0) {
            if(s1[p-1] == s2[q-1]) {
                ans += s1[p-1];
                p--;
                q--;
            }
            else {
                if(dp[p-1][q] >= dp[p][q-1]) {
                    ans += s1[p-1];
                    p--;
                }
                else {
                    ans += s2[q-1];
                    q--;
                }
            }
        }
        while(p>0) {
            ans += s1[p-1];
            p--;
        }
        while(q>0) {
            ans += s2[q-1];
            q--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};