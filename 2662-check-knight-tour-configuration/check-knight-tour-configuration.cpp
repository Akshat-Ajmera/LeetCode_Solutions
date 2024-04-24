class Solution {
private:
    bool check(int n, int row, int col) {
        return !(row < 0 || row >= n || col < 0 || col >= n);
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]) return false;
        int n = grid.size(), cnt = 0, row = 0, col = 0;
        bool flag = false;
        vector<pair<int, int>> dir = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        while(cnt < n*n - 1) {
            flag = false;
            for(int i=0; i<8; i++) {
                int drow = row + dir[i].first, dcol = col + dir[i].second;
                if(!check(n, drow, dcol)) continue;
                if(grid[drow][dcol] == cnt + 1) {
                    row = drow;
                    col = dcol;
                    cnt++;
                    flag = true;
                }
            }
            if(!flag) return false; 
        }
        return true;
    }
};