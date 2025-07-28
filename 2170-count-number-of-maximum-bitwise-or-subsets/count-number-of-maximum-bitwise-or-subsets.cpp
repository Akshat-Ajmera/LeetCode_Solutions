class Solution {
private:
    void solve(vector<int>& v, int& cnt, int& max_or, int orr, int ind) {
        if(ind == v.size()) {
            if(orr == max_or) {
                cnt++;
            }
            return;
        }
        solve(v, cnt, max_or, orr | v[ind], ind + 1);
        solve(v, cnt, max_or, orr, ind + 1);
        return;
    }
public:
    int countMaxOrSubsets(vector<int>& v) {
        int max_or = 0, cnt = 0;
        for(int it : v) max_or |= it;
        solve(v, cnt, max_or, 0, 0);
        return cnt;
    }
};