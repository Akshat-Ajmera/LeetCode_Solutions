class Solution {
private:
    // void bfs(vector<vector<int>> &g, vector<vector<int>> &vis, queue<pair<int,int>> &q, int c) {
    //     while(!q.empty()) {
    //         auto it = q.front();
    //         int row = it.first, col = it.second;
    //         g[row][col] = c;
    //         vis[row][col] = 1;
    //         q.pop();
    //         int drow[4] = {0,-1,1,0}, dcol[4] = {-1,0,0,1};
    //         for(int i=0; i<4; i++) {
    //             int nrow = row+drow[i], ncol = col+dcol[i];
    //             if(nrow<0 || nrow>=g.size() || ncol<0 || ncol>=g.size() || vis[nrow][ncol] || !g[nrow][ncol]) {
    //                 continue;
    //             }
    //             q.push({nrow,ncol});
    //             // cout << "push " << nrow << " " << ncol << endl;
    //             vis[nrow][ncol] = 1;
    //         }
    //     }
    // }
    void dfs(vector<vector<int>> &g, vector<vector<int>> &vis, int i, int j) {
        if(i>=g.size() || i<0 || j>=g.size() || j<0 || vis[i][j] || !g[i][j]) {
            return;
        }
        vis[i][j] = 1;
        g[i][j] = 2;
        int drow[4] = {-1,0,1,0}, dcol[4] = {0,1,0,-1};
        for(int a=0; a<4; a++) {
            dfs(g,vis,i+drow[a],j+dcol[a]);
        }
    }
    void bfs2(vector<vector<int>> &g, vector<vector<int>> &vis, queue<pair<int,int>> &q, int &dist) {
        while(!q.empty()) {
            int siz = q.size();
            while(siz--) {
                auto it = q.front();
                int row = it.first, col = it.second;
                if(g[row][col] == 2) {
                    return;
                }
                q.pop();
                int cnt = 0;
                int drow[4] = {0,-1,1,0}, dcol[4] = {-1,0,0,1};
                for(int i=0; i<4; i++) {
                    int nrow = row + drow[i], ncol = col + dcol[i];
                    if(nrow<0 || nrow>=g.size() || ncol<0 || ncol>=g.size() || vis[nrow][ncol]) {
                        continue;
                    }
                    q.push({nrow,ncol});
                    cnt++;
                    vis[nrow][ncol] = 1;
                }
            }
            dist++;
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int> (n, 0));
        // queue<pair<int,int>> q;
        bool flag = false;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]) {
                    // q.push({i,j});
                    dfs(grid,vis,i,j);
                    flag = true;
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "\n";
        //     for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // for(int i=0; i<n; i++) {
        //     for(int j=0; j<n; j++) {
        //         if(grid[i][j] == 1) {
        //             int dist = 0;
        //             vector<vector<int>> vis1(n, vector<int> (n,0));
        //             queue<pair<int,int>> q1;
        //             q1.push({i,j});
        //             bfs2(grid,vis1,q1,dist);
        //             vis1[i][j] = 1;
        //             ans = min(ans,dist);
        //         }
        //     }
        // }
        set<pair<int,int>> st1, st2;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j]==1) {
                    st1.insert({i,j});
                }
                else if(grid[i][j]==2) {
                    st2.insert({i,j});
                }
            }
        }
        int ans = INT_MAX;
        for(auto it1 : st1) {
            for(auto it2 : st2) {
                ans = min(ans,abs(it1.first-it2.first)+abs(it1.second-it2.second));
            }
        }
        return ans-1;
    }
};