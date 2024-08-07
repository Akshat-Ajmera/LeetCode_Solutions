class Solution {
public:
    int minDays(vector<int> &v, int m, int k) {
        int n = v.size(), lo = INT_MAX, hi = 0, mid, ans = 0, K, M;
        for(auto it : v) {
            lo = min(lo, it);
            hi = max(hi, it);
        }
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            K = 0, M = 0;
            for(int i=0; i<n; i++) {
                if(v[i] <= mid) {
                    K++;
                }
                else {
                    K = 0;
                    continue;
                }
                if(K == k) {
                    M++;
                    K = 0;
                }
            }
            if(M >= m) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        if(!ans) return -1;
        else return ans;
    }
};