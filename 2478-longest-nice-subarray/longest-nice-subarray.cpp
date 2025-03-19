class Solution {
public:
    int longestNiceSubarray(vector<int>& v) {
        int n = v.size(), ans = 0, i = 0, j = 0, mask = 0;
        while(j < n) {
            while(mask & v[j]) {
                mask ^= v[i];
                i++;
            }
            mask |= v[j];
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};