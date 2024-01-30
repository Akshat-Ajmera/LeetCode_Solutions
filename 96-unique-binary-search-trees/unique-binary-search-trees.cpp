class Solution {
private:
    long long solve(vector<long long> &dp, int n) {
        if(n==0 || n==1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        long long ans = 0;
        for(int i=1; i<=n; i++) {
            ans += solve(dp,i-1) * solve(dp,n-i);
        }
        return dp[n] = ans;
    }
public:
    long long numTrees(int n) {
        vector<long long> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;
        return solve(dp,n);
    }
};