class Solution {
private:
    int drow[4] = {-1,0,1,0}, dcol[4] = {0,-1,0,1};
    bool check(int r, int c, int m, int n, vector<vector<int>> &vis, vector<vector<int>> &img, int color, int color1) {
        return !(r<0 || r>=m || c<0 || c>=n || vis[r][c] || img[r][c]!=color1);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size(), row, col, nrow, ncol, color1;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        color1 = image[sr][sc];
        q.push({sr,sc});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            row = it.first;
            col = it.second;
            image[row][col] = color;
            for(int i=0; i<4; i++) {
                nrow = row + drow[i];
                ncol = col + dcol[i];
                if(check(nrow,ncol,m,n,vis,image,color,color1)) {
                    vis[nrow][ncol] = 1;
                    image[nrow][ncol] = color;
                    q.push({nrow,ncol});
                }
            }
        }
        return image;
    }
};