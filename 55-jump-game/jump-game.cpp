class Solution {
    bool solve(vector<int> &v, int n, vector<int> &dp, int siz) {
        if(n == v.size()-1) {
            return true;
        }
        if(!v[n]) {
            return false;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        bool ans = false;
        for(int i=1; n+i<siz && i<=v[n]; i++) {
            ans |= solve(v,n+i,dp,siz);
            if(ans) {
                return ans;
            }
        }
        return dp[n] = ans;
    }
public:
    bool canJump(vector<int>& nums) {
        int siz = nums.size();
        vector<int> dp(siz,-1);
        return solve(nums,0,dp,siz);
    }
};