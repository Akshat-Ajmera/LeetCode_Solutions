class Solution {
private:
    void solve(vector<int> &v, int t, int n, set<vector<int>> &st, vector<int> u) {
        if(!t) {
            st.insert(u);
            return;
        }
        if(n<0) {
            return;
        }
        solve(v,t,n-1,st,u);
        while(t >= v[n]) {
            u.push_back(v[n]);
            solve(v,t-v[n],n,st,u);
            t -= v[n];
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        int n = c.size();
        set<vector<int>> st;
        vector<int> u;
        solve(c,t,n-1,st,u);
        vector<vector<int>> ans;
        for(auto &it : st) {
            ans.push_back(it);
        }
        return ans;
    }
};