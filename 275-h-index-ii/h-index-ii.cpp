class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n = cit.size(), lo = 0, hi = n-1, mid, ans = 0;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(cit[mid] < n - mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return n - lo;
    }
};