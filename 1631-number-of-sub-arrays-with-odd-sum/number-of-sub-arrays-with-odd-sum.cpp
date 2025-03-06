class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size(), ans = 0, mod = 1e9 + 7;
        vector<int> pre(n+1, 0), oddCnt(n+1, 0), evenCnt(n+1, 0);
        for(int i=0; i<n; i++) {
            pre[i+1] = pre[i] + arr[i];
        }
        for(int i=n-1; i>=0; i--) {
            evenCnt[i] = evenCnt[i+1];
            oddCnt[i] = oddCnt[i+1];
            if(pre[i+1] % 2) oddCnt[i]++;
            else evenCnt[i]++;
        }
        cout << endl;
        for(int i=0; i<=n; i++) {
            if(pre[i] % 2) ans = (ans + evenCnt[i]) % mod;
            else ans = (ans + oddCnt[i]) % mod;
        }
        return ans;
    }
};