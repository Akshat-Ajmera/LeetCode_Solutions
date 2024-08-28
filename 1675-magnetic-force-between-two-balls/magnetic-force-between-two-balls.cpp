class Solution {
private:
    bool possible(vector<int> &v, int m, int dist) {
        int cnt = 1, last = 0, n = v.size();
        for(int i=1; i<n; i++) {
            if(v[i] - v[last] >= dist) {
                cnt++;
                last = i;
            }
        }
        return (cnt >= m);
    }
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size(), lo = INT_MAX, hi = pos[n-1] - pos[0], mid, ans;
        for(int i=0; i<n-1; i++) lo = min(lo, pos[i+1] - pos[i]);
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            if(possible(pos, m, mid)) {
                ans = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};