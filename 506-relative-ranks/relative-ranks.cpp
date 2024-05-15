class Solution {
public:
    vector<string> findRelativeRanks(vector<int> &score) {
        int n = score.size(), cnt = 0;
        vector<string> ans(n);
        map<int, int> mp;
        for(int i=0; i<n; i++) mp[-score[i]] = i;
        for(auto &it : mp) {
            if(cnt == 0) ans[it.second] = "Gold Medal";
            else if(cnt == 1) ans[it.second] = "Silver Medal";
            else if(cnt == 2) ans[it.second] = "Bronze Medal";
            else ans[it.second] = to_string(cnt + 1);
            cnt++;
        }
        return ans;
    }
};