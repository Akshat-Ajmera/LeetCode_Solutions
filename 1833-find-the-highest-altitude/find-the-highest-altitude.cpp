class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int n = g.size(), ans = INT_MIN;
        vector<int> h(n+1,0);
        for(int i=1; i<=n; i++) {
            h[i] = h[i-1] + g[i-1];
        }
        for(int i=0; i<=n; i++) {
            ans = max(ans, h[i]);
        }
        return ans;
    }
};