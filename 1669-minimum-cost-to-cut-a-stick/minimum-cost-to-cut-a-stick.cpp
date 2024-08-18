class Solution {
private:
    int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(dp[i][j] != -1) return dp[i][j];
        if(i > j) return 0;
        int ans = INT_MAX, cost;
        for(int idx=i; idx<=j; idx++) {
            cost = cuts[j+1] - cuts[i-1] + solve(i, idx-1, cuts, dp) + solve(idx+1, j, cuts, dp);
            ans = min(ans, cost);
        }
        return dp[i][j] = ans;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m, vector<int> (m, -1));
        return solve(1, cuts.size()-2, cuts, dp);
    }
};