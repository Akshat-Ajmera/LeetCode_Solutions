class Solution {
public:
    int largestAltitude(vector<int>& g) {
        int n = g.size(), ans = 0, sum = 0;
        for(int i=0; i<n; i++) {
            sum += g[i];
            ans = max(ans, sum);
        }
        return ans;
    }
};