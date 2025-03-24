class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int i = v[0][0], j = v[0][1], n = v.size();
        for(int k=1; k<n; k++) {
            if(v[k][0] <= j) j = max(v[k][1], j);
            else {
                ans.push_back({i, j});
                if(k < n) {
                    i = v[k][0], j = v[k][1];
                }
            }
        }
        ans.push_back({i, j});
        return ans;
    }
};