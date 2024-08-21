class Solution {
private:
    bool solve(string &s, int l, int r, vector<vector<int>> &dp) {
        if(l >= r) return true;
        if(dp[l][r] != -1) return dp[l][r];
        bool ans = false;
        if(s[l] == s[r]) ans = solve(s, l+1, r-1, dp);
        return dp[l][r] = ans;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size(), mxm = 0, ind = 0;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        solve(s, 0, n-1, dp);
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                if(!solve(s, i, j, dp)) continue;
                if(j-i+1 > mxm) {
                    mxm = j-i+1;
                    ind = i;
                }
            }
        }
        return s.substr(ind, mxm);
    }
};