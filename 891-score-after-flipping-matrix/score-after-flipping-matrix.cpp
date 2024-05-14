class Solution {
private:
    int rowCounter(vector<vector<int>> &grid, int row, int n) {
        int ans = 0;
        for(int col=0; col<n; col++) ans += grid[row][col];
        return ans;
    }
    int colCounter(vector<vector<int>> &grid, int col, int m) {
        int ans = 0;
        for(int row=0; row<m; row++) ans += grid[row][col];
        return ans;
    }
    void rowChanger(vector<vector<int>> &grid, int row, int n) {
        for(int col=0; col<n; col++) grid[row][col] = 1 - grid[row][col];
    }
    void colChanger(vector<vector<int>> &grid, int col, int m) {
        for(int row=0; row<m; row++) grid[row][col] = 1 - grid[row][col];
    }
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++) {
            if(!grid[i][0]) rowChanger(grid, i, n);
        }
        for(int j=1; j<n; j++) {
            if(colCounter(grid, j, m) < ((m + 1) / 2)) colChanger(grid, j, m);
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans += (grid[i][j] * pow(2, n - j - 1));
            }
        }
        return ans;
    }
};