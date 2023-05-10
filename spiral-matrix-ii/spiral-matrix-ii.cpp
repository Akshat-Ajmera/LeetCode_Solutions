class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n,0));
        int i=0, j=0, k=1, p, q; 
        while(!ans[i][j]) {
            while(j<n && !ans[i][j]) {
                ans[i][j] = k;
                k++;
                j++;
            }
            if(q == j) {
                break;
            }
            i++;
            j--;
            p = i;
            q = j;
            while(i<n && !ans[i][j]) {
                ans[i][j] = k;
                k++;
                i++;
            }
            if(p == i) {
                break;
            }
            i--;
            j--;
            p = i;
            q = j;
            while(j>=0 && !ans[i][j]) {
                ans[i][j] = k;
                k++;
                j--;
            }
            if(q == j) {
                break;
            }
            i--;
            j++;
            p = i;
            q = j;
            while(i>=0 && !ans[i][j]) {
                ans[i][j] = k;
                k++;
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