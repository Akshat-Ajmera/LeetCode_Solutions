class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        if(n < 3) return 0;
        vector<int> pre(n, 0), suf(n, 0);
        for(int i=1; i<n; i++) pre[i] = max(pre[i-1], height[i-1]);
        for(int i=n-2; i>=0; i--) suf[i] = max(suf[i+1], height[i+1]);
        for(int i=0; i<n; i++) ans += max(min(pre[i], suf[i]) - height[i], 0);
        return ans;
    }
};