class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size(), lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            if((arr[mid] - mid - 1) < k) lo = mid + 1;
            else hi = mid - 1;
        }
        return (hi + 1 + k);
    }
};