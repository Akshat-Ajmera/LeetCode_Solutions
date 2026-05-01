class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), ans, tot = 0, const_sub = 0;
        for(int i=0; i<n; i++) {
            tot += (i * nums[i]);
            const_sub += nums[i];
        }
        ans = tot;
        for(int i=0; i<n-1; i++) {
            tot += (nums[i] * n) - const_sub;
            ans = max(ans, tot);
        }
        return ans;
    }
};