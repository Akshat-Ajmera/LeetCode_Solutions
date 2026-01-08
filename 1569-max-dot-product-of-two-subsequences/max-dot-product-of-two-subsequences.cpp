class Solution {
private:
    int solve(int i, int j, vector<int> &u, vector<int> &v, vector<vector<int>> &dp) {
        if(i < 0 || j < 0) return -50000000;
        if(dp[i][j] != -1) return dp[i][j];
        int a = solve(i-1, j-1, u, v, dp);
        int b = solve(i-1, j, u, v, dp);
        int c = solve(i, j-1, u, v, dp);
        int d = (u[i] * v[j]);
        return dp[i][j] = max({a + d, b, c, d});
    }
public:
    int maxDotProduct(vector<int>& u, vector<int>& v) {
        vector<vector<int>> dp(u.size(), vector<int> (v.size(), -1));
        return solve(u.size()-1, v.size()-1, u, v, dp);
        int ans = solve(u.size()-1, v.size()-1, u, v, dp), zero = 0, mnm_u =INT_MAX, mnm_v = INT_MAX, mxm_u = INT_MIN, mxm_v = INT_MIN;
        if(ans) return ans;
        for(int &it : u) {
            if(!it) zero++;
            mxm_u = max(mxm_u, it);
            mnm_u = min(mnm_u, it);
        }
        for(int &it : v) {
            if(!it) zero++;
            mxm_v = max(mxm_v, it);
            mnm_v = min(mnm_v, it);
        }
        if(!zero) ans = max({(mxm_u * mxm_v), (mxm_u * mnm_v), (mnm_u * mxm_v), (mnm_u * mnm_v)});
        return ans;
    }
};