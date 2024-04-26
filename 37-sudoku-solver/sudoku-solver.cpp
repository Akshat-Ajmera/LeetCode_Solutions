class Solution {
private:
    bool check(int row, int col, char c, vector<vector<char>> &board) {
        for(int i=0; i<9; i++) {
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
            if(board[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == c) return false;
        }
        return true;
    }
    bool calc(vector<vector<char>> &board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] != '.') continue;
                for(char c='1'; c<='9'; c++) {
                    if(!check(i, j, c, board)) continue;
                    board[i][j] = c;
                    if(calc(board) == true) return true;
                    else board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> alr(27, vector<int> (9, 0));
        calc(board);
    }
};