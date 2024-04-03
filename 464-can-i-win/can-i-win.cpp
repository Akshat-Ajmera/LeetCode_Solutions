class Solution {
private:
    bool calc(int bitmask, int player, int mxm, int tot, vector<vector<int>> &dp) {
        if(tot <= 0) return true;
        if(dp[bitmask][player] != -1) return dp[bitmask][player];
        for(int i=0; i<mxm; i++) {
            if((1 << i) & bitmask) continue;
            if(tot <= i+1 || !calc(bitmask | (1 << i), player^1, mxm, tot-i-1, dp)) {
                return dp[bitmask][player] = true;
            }
        }
        return dp[bitmask][player] = false;
    }
public:
    bool canIWin(int mxm, int tot) {
        if(!tot || mxm >= tot) return true;
        if((mxm*(mxm+1))/2 < tot) return false;
        vector<vector<int>> dp(1 << (mxm), vector<int> (2, -1));
        return calc(0, 0, mxm, tot, dp);
    }
};