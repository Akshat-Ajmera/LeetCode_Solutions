class Solution {
private:
    bool valid(int row, int col, int n, int m) {
        return !(row<0 || row>=n || col<0 || col>=m);
    } 
public:
    int minimumEffortPath(vector<vector<int>> &h) {
        int n = h.size(), m = h[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int row = it.second.first, col = it.second.second, diff = it.first;
            if(row == n-1 && col == m-1) {
                return diff;
            }
            int drow[4] = {0,-1,0,1};
            int dcol[4] = {1,0,-1,0};
            for(int i=0; i<4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(valid(nrow,ncol,n,m)) {
                    int newDiff = max(abs(h[nrow][ncol] - h[row][col]), diff);
                    if(newDiff < dist[nrow][ncol]) {
                        dist[nrow][ncol] = newDiff;
                        pq.push({newDiff, {nrow, ncol}});
                    }
                }
            }
        }
        return 0;
    }
};