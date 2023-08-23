class Solution {
public:
    int maxArea(vector<int>& h) {
        int n = h.size();
        long long ans = min(h[n-1],h[0])*(n-1), i=0, j=n-1;
        while(i<j && i>=0 && j<n) {
            if(h[j] <= h[i]) {
                j--;
            }
            else {
                i++;
            }
            ans = max(ans, min(h[j],h[i])*(j-i));
        }
        return ans;
    }
};