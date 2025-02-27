class Solution {
private:
    int solve(vector<int> &arr, int prev, int curr) {
        int nextVal = arr[prev] + arr[curr];
        auto it = lower_bound(arr.begin() + curr + 1, arr.end(), nextVal);

        if (it == arr.end() || *it != nextVal) return 2;
        int nextIdx = it - arr.begin();
        return 1 + solve(arr, curr, nextIdx);
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size(), maxLen = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                maxLen = max(maxLen, solve(arr, i, j));
            }
        }
        return maxLen > 2 ? maxLen : 0;
    }
};
