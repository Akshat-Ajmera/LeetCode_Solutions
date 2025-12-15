class Solution {
private:
    long long totalPeriods(long long n) {
        return ((n * (n + 1))) / 2;
    }
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0, last = -1, winLen = 1;
        for(int i=1; i<prices.size(); i++) {
            if(prices[i-1] - prices[i] == 1) winLen++;
            else {
                ans += totalPeriods(winLen);
                winLen = 1;
            }
        }
        ans += totalPeriods(winLen);
        return ans;
    }
};