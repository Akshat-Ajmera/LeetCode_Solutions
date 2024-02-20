class Solution {
private:
    int solve(string &s, int n, vector<int> &dp) {
        if(n < 0) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int one = 0;
        if(n>=0) {
            int val1 = (s[n]-'0');
            if(val1 >= 1) {
                one = solve(s, n-1, dp);
            }
        }
        int two = 0;
        if(n>=1 && s[n-1] != '0') {
            int val2 = ((s[n-1]-'0')*10 + (s[n]-'0'));
            if(val2 <= 26 && val2 >= 1) {
                two = solve(s, n-2, dp);
            }
        }
        return dp[n] = one + two;
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(s, n-1, dp);
    }
};