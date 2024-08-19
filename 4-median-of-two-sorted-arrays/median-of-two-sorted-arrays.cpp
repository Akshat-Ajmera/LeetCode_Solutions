class Solution {
public:
    double findMedianSortedArrays(vector<int> &v1, vector<int> &v2) {
        int n1 = v1.size(), n2 = v2.size(), n = (n1 + n2), lo, hi, mid1, mid2, l1, l2, r1, r2;
        if(n1 > n2) return findMedianSortedArrays(v2, v1);
        lo = 0, hi = n1;
        while(lo <= hi) {
            l1 = l2 = INT_MIN;
            r1 = r2 = INT_MAX;
            mid1 = (lo + ((hi - lo) / 2));
            mid2 = ((n + 1) / 2) - mid1;
            if(mid1 < n1) r1 = v1[mid1];
            if(mid2 < n2) r2 = v2[mid2];
            if(mid1 >= 1) l1 = v1[mid1-1];
            if(mid2 >= 1) l2 = v2[mid2-1];
            if(l1 <= r2 && l2 <= r1) {
                if(n % 2) return (double)max(l1, l2);
                return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) hi = mid1 - 1;
            else lo = mid1 + 1;
        }
        return 0.0;
    }
};


