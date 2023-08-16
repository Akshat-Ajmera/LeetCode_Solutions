class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), mn = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n,-1));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<n; i++) {
            dp[i][0] = dp[i-1][0] + triangle[i][0];
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<i+1; j++) {
                if(i-1<j) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(dp[n-1][i] < mn) {
                mn = dp[n-1][i];
            }
        }
        return mn;
    }
};