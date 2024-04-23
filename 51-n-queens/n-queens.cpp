class Solution {
private:
    bool check(int row, int col, vector<string> &board) {
        int n = board.size(), i = row, j = col;
        while(j>=0) {
            if(board[i][j] == 'Q') return false;
            j--;
        }
        i = row, j = col;
        while(i>=0 && j>=0) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i = row, j = col;
        while(i<n && j>=0) {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans) {
        int n = board.size();
        if(col == n) {
            ans.push_back(board);
            return;
        }
        for(int row=0; row<n; row++) {
            if(!check(row, col, board)) continue;
            board[row][col] = 'Q';
            solve(col + 1, board, ans);
            board[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i=0; i<n; i++) board[i] = s;
        solve(0, board, ans);
        return ans;
    }
};