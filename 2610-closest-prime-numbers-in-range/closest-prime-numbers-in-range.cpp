class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int a = 0, b = 0, mnm = INT_MAX;
        vector<int> ans = {-1, -1};
        vector<bool> prime(right+1, true);
        prime[0] = prime[1] = false;
        for(int i=2; i*i<=right+1; i++) {
            if(prime[i]) {
                for(int j=i*i; j<=right+1; j+=i) {
                    prime[j] = false;
                }
            }
        }
        for(int i=left; i<=right; i++) {
            if(prime[i] && !b) {
                b = i;
                continue;
            }
            else if(prime[i]) {
                a = b;
                b = i;
            }
            if(a && b && (b - a < mnm)) {
                ans = {a, b};
                mnm = b - a;
            }
        }
        return ans;
    }
};