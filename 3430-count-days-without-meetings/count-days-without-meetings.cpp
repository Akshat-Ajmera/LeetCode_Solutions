class Solution {
public:
    int countDays(int days, vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> res;
        int i = v[0][0], j = v[0][1], n = v.size(), ans = 0;
        for(int k=1; k<n; k++) {
            if(v[k][0] <= j) j = max(v[k][1], j);
            else {
                res.push_back({i, j});
                if(k < n) {
                    i = v[k][0], j = v[k][1];
                }
            }
        }
        res.push_back({i, j});
        for(int k=1; k<res.size(); k++) ans += res[k][0] - res[k-1][1] - 1;
        ans += res[0][0] - 1 + days - res[res.size() - 1][1];
        return ans;
    }
};