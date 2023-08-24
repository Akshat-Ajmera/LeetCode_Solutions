class Solution {
// private:
//     int solve(vector<int> &p, vector<int> &dp, int n) {
//         if(!n) {
//             return 0;
//         }
//         if(n==1) {
//             return max(0,p[1]-p[0]);
//         }
//         return 
//     }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), pft = INT_MIN, mnm = INT_MAX;
        if(!n) {
            return n;
        }
        for(int i=0; i<n; i++) {
            mnm = min(mnm, prices[i]);
            pft = max(pft,prices[i]-mnm);
        }
        return pft;
    }
};