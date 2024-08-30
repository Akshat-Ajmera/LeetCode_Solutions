class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), lo = 0, hi = m*n - 1, mid, row, col;
        while(lo <= hi) {
            mid = lo + (hi - lo) / 2;
            row = mid / n, col = mid % n;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        return false;
    }
};