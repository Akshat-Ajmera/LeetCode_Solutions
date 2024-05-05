class Solution {
private:
    bool check(int row, int col, int n) {
        return !(row < 0 || col < 0 || row >= n || col >= n);
    }
    double solve(int row, int col, int n, int k, vector<vector<vector<double>>> &dp) {
        if(!check(row, col, n)) return 1;
        if(!k) return 0;
        if(dp[row][col][k] != -1) return dp[row][col][k];
        double ans = 0.0;
        int drow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
        int dcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        for(int i=0; i<8; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
          ans += (0.125 * solve(nrow, ncol, n, k-1, dp));
        }
        return dp[row][col][k] = ans;
    }
public:
    double knightProbability(int n, int k, int row, int col) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k+1, -1)));
        return 1 - solve(row, col, n, k, dp);
    }
};