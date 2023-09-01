class Solution {
private:
    int solve(vector<int> &v, vector<vector<int>> &dp, int i, int j) {
        if(i>j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int k=i; k<=j; k++) {
            ans = max(ans, v[i-1]*v[k]*v[j+1] + solve(v,dp,i,k-1) + solve(v,dp,k+1,j));
        }
        return dp[i][j] = ans;
    }
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, -1));
        return solve(nums,dp,1,n);
    }
};