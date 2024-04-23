class Solution {
private:
    bool check(int n, int row, int col, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag) {
        return !(leftRow[row] || upperDiag[n - 1 + col - row] || lowerDiag[row + col]);
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDiag, vector<int> &lowerDiag) {
        int n = board.size();
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(!check(n, row, col, leftRow, upperDiag, lowerDiag)) continue;
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiag[row + col] = 1;
            upperDiag[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftRow, upperDiag, lowerDiag);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiag[row + col] = 0;
            upperDiag[n - 1 + col - row] = 0;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        vector<int> leftRow(n, 0), upperDiag(2*n, 0), lowerDiag(2*n, 0);  
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, board, ans, leftRow, upperDiag, lowerDiag);
        return ans;
    }
};