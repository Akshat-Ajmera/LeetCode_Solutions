class Solution {
private:
    void solve(int i, int n, int k, vector<int> v) {
        if(!k) {
            ans.push_back(v);
            return;
        }
        if(i > n) {
            return;
        }
        for(int j=i; j<=n; j++) {
            v.push_back(j);
            solve(j+1, n, k-1, v);
            v.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        solve(1, n, k, v);
        return ans;
    }
};