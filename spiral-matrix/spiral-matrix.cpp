class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans, ans1;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int i = 0, j = 0, p, q;
        while(!vis[i][j] && i<m && j<n) {
            while(j<n && !vis[i][j]) {
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                j++;
            }
            if(q == j) {
                break;
            }
            i++;
            j--;
            p = i;
            q = j;
            while(i<m && !vis[i][j]) {
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                i++;
            }
            if(p == i) {
                break;
            }
            i--;
            j--;
            p = i;
            q = j;
            while(j>=0 && !vis[i][j]) {
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                j--;
            }
            if(q == j) {
                break;
            }
            i--;
            j++;
            p = i;
            q = j;
            while(i>=0 && !vis[i][j]) {
                ans.push_back(matrix[i][j]);
                vis[i][j] = 1;
                i--;
            }
            if(p == i) {
                break;
            }
            i++;
            j++;
            p = i;
            q = j;
        }
    return ans;
    }
};