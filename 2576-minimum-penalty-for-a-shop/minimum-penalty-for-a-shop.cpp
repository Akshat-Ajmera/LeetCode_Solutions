class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size(), ans, mnm = INT_MAX;
        vector<int> preN(n, 0), sufY(n, 0);
        if(customers[0] == 'N') preN[0] = 1;
        for(int i=1; i<n; i++) {
            preN[i] += preN[i-1];
            if(customers[i] == 'N') preN[i]++;
        }
        if(customers[n-1] == 'Y') sufY[n-1] = 1;
        for(int i=n-2; i>=0; i--) {
            sufY[i] += sufY[i+1];
            if(customers[i] == 'Y') sufY[i]++;
        }
        if(sufY[0] <= mnm) {
            ans = 0;
            mnm = sufY[0];
        }
        for(int i=0; i<n-1; i++) {
            if(preN[i] + sufY[i+1] < mnm) {
                ans = i+1;
                mnm = preN[i] + sufY[i+1];
            }
        }
        if(preN[n-1] < mnm) ans = n;
        return ans;
    }
};