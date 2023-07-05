class Solution {
private:
    int drow[8]={0,1,0,-1,1,-1,1,-1}, dcol[8]={1,0,-1,0,-1,1,1,-1};
    bool check(int n, int row, int col, vector<vector<int>>& grid) {
        return (row<n && row>=0 && col<n && col>=0 && !grid[row][col]);
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) {
            return -1;
        }
        int n=grid.size();
        if(n==1) {
            if(grid[0][0]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        vector<vector<int>> dist(n,vector<int>(n,1e6));
        dist[0][0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()) {
            int row=q.front().first, col=q.front().second;
            q.pop();
            for(int i=0; i<8; i++) {
                int nrow = row+drow[i], ncol = col+dcol[i];
                if(check(n,nrow,ncol,grid)) {
                    if(dist[nrow][ncol]>dist[row][col]+1) {
                        dist[nrow][ncol] = dist[row][col]+1;
                        if(nrow==n-1 && ncol==n-1) {
                            return dist[n-1][n-1];
                        }
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return -1;
    }
};