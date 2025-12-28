class Solution {
private:
    int binarySearch(vector<int> &v, int n) {
        int lo = 0, hi = n - 1, mid, ans = n;
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            if(v[mid] >= 0) lo = mid + 1;
            else {
                ans = mid;
                hi = mid - 1;
            }
        }
        if(!ans) return n;
        if(ans == n) return 0;
        return n - ans;
    }
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            ans += binarySearch(grid[i], n);
        }
        return ans;
    }
};