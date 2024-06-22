class Solution {
private:
    bool check(vector<vector<int>> &temp, int row, int col) {
        return !(row < 0 || row >= temp.size() || col < 0 || col >= temp[0].size());
    }
    int cnt(vector<vector<int>> &temp, int i, int j) {
        int ans = 0;
        int drow[4] = {0, 1, 0, -1}, dcol[4] = {-1, 0, 1, 0}, diag1[4] = {-1, 1, -1, 1}, diag2[4] = {1, 1, -1, -1};
        for(int a=0; a<4; a++) {
            int nrow = i + drow[a], ncol = j + dcol[a];
            if(!check(temp, nrow, ncol)) continue;
            if(temp[nrow][ncol]) ans++;
        }
        for(int a=0; a<4; a++) {
            int ndiag1 = i + diag1[a], ndiag2 = j + diag2[a];
            if(!check(temp, ndiag1, ndiag2)) continue;
            if(temp[ndiag1][ndiag2]) ans++;
        }
        return ans;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp(m, vector<int> (n));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp[i][j] = board[i][j];
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(cnt(temp, i, j) < 2) {
                    board[i][j] = 0;
                }
                else if(cnt(temp, i, j) > 3 && temp[i][j]) {
                    board[i][j] = 0;
                }
                else if(cnt(temp, i, j) == 3 && !temp[i][j]) {
                    board[i][j] = 1;
                }
            }
        }
        return;
    }
};