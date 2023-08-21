class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.size(), n=s2.size();
        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++) {
                if(s1[i-1]==s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int siz = m+n-dp[m][n];
        string s = "";
        for(int i=0; i<siz; i++) {
            s += " ";
        }
        int ind = siz-1;
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
            }
        }
        int i=m, j=n;
        while(i>0 && j>0) {
            if(s1[i-1]==s2[j-1]) {
                s[ind] = s1[i-1];
                i--;
                j--;
                ind--;
            }
            else if(dp[i-1][j] > dp[i][j-1]) {
                s[ind] = s1[i-1];
                ind--;
                i--;
            }
            else {
                s[ind] = s2[j-1];
                ind--;
                j--;
            }
        }
        while(i>0) {
            s[ind] = s1[i-1];
            ind--;
            i--;
        }
        while(j>0) {
            s[ind] = s2[j-1];
            ind--;
            j--;
        }
        return s;
    }
};