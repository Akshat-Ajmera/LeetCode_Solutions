class Solution {
public:
    vector<int> drow = {0,-1,0,1}, dcol = {-1,0,1,0};
public:
    bool check(int row, int col, int m, int n, vector<vector<int>>& grid) {
        if(row>=m || row<0 || col>=n || col<0) {
            return false;
        }
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==2) {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            int siz = q.size();
            while(siz--) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                for(int i=0; i<4; i++) {
                    int nrow = row + drow[i];
                    int ncol = col + dcol[i];
                    if(check(nrow, ncol, m, n, grid)) {
                        if(grid[nrow][ncol]==1) {
                            grid[nrow][ncol] = 2;
                            q.push({nrow, ncol});
                        }
                    }
                }
            }
            time++;
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                } 
            }
        }
        if(!time) {
            return time;
        }
        return --time;
    }
};