class Solution {
private:
    int nextValidInd(vector<vector<int>> &events, int i) {
        int lo = i+1, hi = events.size() - 1, mid, ans = events.size();
        while(lo <= hi) {
            mid = lo + ((hi - lo) / 2);
            if(events[mid][0] > events[i][1]) {
                ans = mid;
                hi = mid - 1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
    int solve(vector<vector<int>> &events, int i, int cnt, vector<vector<int>> &dp) {
        if(i == events.size() || !cnt) return 0;
        if(dp[i][cnt] != -1) return dp[i][cnt];
        int notTake = solve(events, i+1, cnt, dp), take = events[i][2] + solve(events, nextValidInd(events, i), cnt-1, dp);
        return dp[i][cnt] = max(take, notTake);
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int> (3, -1));
        return solve(events, 0, 2, dp);
    }
};