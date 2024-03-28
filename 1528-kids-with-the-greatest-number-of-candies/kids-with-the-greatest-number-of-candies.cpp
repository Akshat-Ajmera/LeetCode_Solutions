class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mxm = 0, n = candies.size();
        for(int i=0; i<n; i++) mxm = max(mxm, candies[i]);
        vector<bool> ans(n, false);
        for(int i=0; i<n; i++) {
            if(candies[i] != mxm) {
                if(candies[i] + extraCandies >= mxm) ans[i] = true;
            }
            else ans[i] = true;
        }
        return ans;
    }
};