class Solution {
public:
    int equalPairs(vector<vector<int>> &g) {
        int n = g.size(), ans = 0;
        map<vector<int>,int> mp;
        for(int i=0; i<n; i++) {
            mp[g[i]]++;
        }
        for(int i=0; i<n; i++) {
            vector<int> temp(n);
            for(int j=0; j<n; j++) {
                temp[j] = g[j][i];
            }
            if(mp.find(temp) != mp.end()) {
                ans += mp[temp];
            }
        }
        return ans;
    }
};