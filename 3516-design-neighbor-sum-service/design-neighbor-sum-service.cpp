class NeighborSum {
private:
    int n;
    vector<vector<int>> matrix;
    unordered_map<int, int> adjSum, diaSum;
public:
    NeighborSum(vector<vector<int>>& grid) {
        n = grid.size();
        matrix.resize(n+2, vector<int> (n+2, 0));
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<n+1; j++) {
                matrix[i][j] = grid[i-1][j-1];
            }
        }
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<n+1; j++) {
                adjSum[matrix[i][j]] = matrix[i-1][j] + matrix[i][j-1] + matrix[i][j+1] + matrix[i+1][j];
                diaSum[matrix[i][j]] = matrix[i-1][j-1] + matrix[i+1][j+1] + matrix[i-1][j+1] + matrix[i+1][j-1];
            }
        }
    }
    int adjacentSum(int value) {
        return adjSum[value];
    }
    int diagonalSum(int value) {
        return diaSum[value];
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */