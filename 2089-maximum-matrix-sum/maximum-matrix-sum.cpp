class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int minus = 0, len = matrix.size(), mnm = INT_MIN, mxm = INT_MAX;
        bool zero = false;
        for(int i=0; i<len; i++) {
            for(int j=0; j<len; j++) {
                if(!matrix[i][j]) zero = true;
                else if(matrix[i][j] < 0) {
                    minus++;
                    mnm = max(mnm, matrix[i][j]);
                }
                else mxm = min(mxm, matrix[i][j]);
                ans += abs(matrix[i][j]);
            }
        }
        if(zero || !(minus % 2)) return ans;
        return ans - 2 * min(mxm, -mnm);
    }
};