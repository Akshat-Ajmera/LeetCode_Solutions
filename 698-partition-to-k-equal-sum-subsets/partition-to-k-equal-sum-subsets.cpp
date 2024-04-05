class Solution {
private:
    bool solve(int bitmask, vector<int> &v, int siz, int k, int subSum, vector<vector<int>> &dp) {
        if(dp[bitmask][k] != -1) return dp[bitmask][k];
        int n = v.size();
        if(__builtin_popcount(bitmask) == n) return !k;
        if(!k) return false;
        bool ans = 0;
        for(int i=0; i<n; i++) {
            if(bitmask & (1 << i)) continue;
            if(siz > v[i]) ans |= solve(bitmask ^ (1 << i), v, siz - v[i], k, subSum, dp);
            if(siz == v[i]) ans |= solve(bitmask ^ (1 << i), v, subSum, k-1, subSum, dp);
        }
        return dp[bitmask][k] = ans;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, siz, bitmask = (1 << n);
        vector<vector<int>> dp((1 << n), vector<int> (k+1, -1));
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % k) return false;
        siz = sum / k;
        return solve(0, nums, siz, k, siz, dp);
    }
};