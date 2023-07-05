//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        if(source==destination) {
            return 0;
        }
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second] = 0;
        int drow[4] = {0,-1,0,1};
        int dcol[4] = {-1,0,1,0};
        queue<pair<int,int>> q;
        q.push(source);
        while(!q.empty()) {
            int row = q.front().first, col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1) {
                    if(dist[nrow][ncol] > dist[row][col]+1) {
                        dist[nrow][ncol] = dist[row][col]+1;
                        q.push({nrow,ncol});
                    }
                }
                if(nrow==destination.first && ncol==destination.second) {
                    return dist[nrow][ncol];
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends