class Solution {
private:
    int solve(string &s, int n, vector<int> &dp) {
        if(n < 0) return 1;
        if(dp[n] != -1) return dp[n];
        int one = 0, two = 0;
        if(n >= 0) {
            int num = s[n] - '0';
            if(num > 0) one = solve(s, n-1, dp);
        }
        if(n >= 1 && s[n-1] != '0') {
            int num = (s[n] - '0') + (10 * (s[n-1] - '0'));
            if(num > 0 && num <= 26) two = solve(s, n-2, dp);
        }
        return dp[n] = one + two;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, s.size()-1, dp);
    }
};