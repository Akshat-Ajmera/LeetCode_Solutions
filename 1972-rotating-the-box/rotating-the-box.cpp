class Solution {
private:
    vector<char> solve(vector<char> &row) {
        int siz = row.size(), last = siz-1;
        for(int i=siz-1; i>=0; i--) {
            if(row[i] == '#') {
                row[i] = '.';
                row[last] = '#';
                last = max(0, last-1);
            }
            else if(row[i] == '*') {
                last = max(0, i-1);
            }
        }
        return row;
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char> (m));
        for(int i=0; i<m; i++) {
            box[i] = solve(box[i]);
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans[i][j] = box[m-j-1][i];
            }
        }
        return ans;
    }
};