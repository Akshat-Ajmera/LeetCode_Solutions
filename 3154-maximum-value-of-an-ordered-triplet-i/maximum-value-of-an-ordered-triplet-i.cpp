class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> pre(n), suf(n);
        pre[0] = nums[0];
        suf[n-1] = nums[n-1];
        for(int i=1; i<n; i++) pre[i] = max(pre[i-1], nums[i-1]);
        for(int i=n-2; i>=0; i--) suf[i] = max(suf[i+1], nums[i+1]);
        for(int j=1; j<n-1; j++) {
            ans = max(ans, (long long)(pre[j] - nums[j]) * suf[j]);
        }
        return ans;
    }
};