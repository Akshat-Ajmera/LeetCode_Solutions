class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int n = v.size(), lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            if(mid != 0 && mid != n-1 && v[mid] > v[mid+1] && v[mid] > v[mid-1]) return mid;
            if(mid == 0 || (v[mid] > v[mid-1] && v[mid] < v[mid+1])) lo = mid;
            if(mid == n-1 || (v[mid] < v[mid-1] && v[mid] > v[mid+1])) hi = mid;
        }
        return mid;
    }
};