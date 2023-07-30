class Solution {
private:
    int climber(vector<int> &dp, int n) {
        if(!n) {
            dp[0] = 1;
            return dp[0];
        }
        if(n<=2) {
            dp[n] = n;
            return dp[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climber(dp,n-1) + climber(dp,n-2);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(46,-1);
        return climber(dp,n);
    }
};