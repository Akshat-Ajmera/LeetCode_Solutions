class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        long long curr = 0, ans;
        for(int i=0; i<prices.size(); i++) curr += (prices[i] * strategy[i]);
        ans = curr;
        for(int i=0; i<k/2; i++) curr -= (prices[i] * strategy[i]);
        for(int i=k/2; i<k; i++) curr += (prices[i] - (prices[i] * strategy[i]));
        ans = max(ans, curr);
        for(int i=1; i<=prices.size()-k; i++) {
            curr += prices[i-1] * strategy[i-1];
            curr -= prices[i-1+(k/2)];
            curr += prices[i+k-1] - (prices[i+k-1] * strategy[i+k-1]);
            ans = max(ans, curr);
        }
        return ans;
    }
};