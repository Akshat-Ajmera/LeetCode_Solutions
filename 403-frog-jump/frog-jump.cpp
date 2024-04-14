class Solution {
private:
    bool solve(vector<int> &v, int n, int k, vector<vector<int>> &dp) {
        if(n == v.size() - 1) return true;
        if(dp[n][k] != -1) return dp[n][k];
        bool ans = false;
        for(int i=n+1; i<v.size(); i++) {
            if(v[i] - v[n] >= k + 2 || v[i] - v[n] <= k - 2) continue;
            ans |= solve(v, i, v[i] - v[n], dp);
        }
        return dp[n][k] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if(stones[1] > 1) return false;
        vector<vector<int>> dp(n+1, vector<int> (2001, -1)); 
        return solve(stones, 0, 0, dp);
    }
};