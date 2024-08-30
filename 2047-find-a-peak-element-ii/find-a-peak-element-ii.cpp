class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size(), lo = 0, hi = n-1, mid;
        while(lo <= hi) {
            mid = (lo + ((hi - lo) / 2));
            int mxmInd = 0;
            for(int i=0; i<m; i++) {
                if(mat[i][mid] > mat[mxmInd][mid]) mxmInd = i;
            }
            int left = mid-1 >= 0 ? mat[mxmInd][mid-1] : -1;
            int right = mid+1 < n ? mat[mxmInd][mid+1] : -1;
            if(mat[mxmInd][mid] > left && mat[mxmInd][mid] > right) return {mxmInd, mid};
            else if(mat[mxmInd][mid] < left) hi = mid - 1;
            else lo = mid + 1;
        }
        return {-1, -1};
    }
};