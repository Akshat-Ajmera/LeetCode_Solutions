class Solution {
public:
    int countSquares(vector<vector<int>>& g) {
        int m=g.size(), n=g[0].size(), ans=0;
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(g[i][j]) {
                    g[i][j] += min({g[i][j-1],g[i-1][j],g[i-1][j-1]});
                }
            }
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                ans += g[i][j];
            }
        }
        return ans;
    }
};