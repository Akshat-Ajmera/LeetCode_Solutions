class Solution {
private:
    int solve(vector<int> &v, int tgt, vector<int> &dp) {
        if(!tgt) return 1;
        if(tgt < 0) return 0;
        if(dp[tgt] != -1) return dp[tgt];
        int n = v.size(), ans = 0;
        for(int i=0; i<n; i++) {
            ans += solve(v, tgt - v[i], dp);
        }
        return dp[tgt] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};