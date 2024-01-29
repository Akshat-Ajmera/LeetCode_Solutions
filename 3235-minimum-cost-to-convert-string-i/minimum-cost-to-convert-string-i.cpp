class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long n = source.size(), m = original.size();
        vector<vector<long long>> d(26, vector<long long> (26, LONG_MAX));
        for(int i=0; i<26; i++) {
            d[i][i] = 0;
        }
        for(long long i=0; i<m; i++) {
            char a = original[i], b = changed[i];
            long long c = cost[i];
            d[a-'a'][b-'a'] = min(c, d[a-'a'][b-'a']);
        }
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                for(int k=0; k<26; k++) {
                    if((d[j][i] >= LONG_MAX) || (d[i][k] >= LONG_MAX)) {
                        continue;
                    }
                    d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
                }
            }
        }
        long long ans = 0;
        for(long long i=0; i<n; i++) {
            char src = source[i], tgt = target[i];
            long long wt = d[src-'a'][tgt-'a'];
            if(wt >= 1e9) {
                return -1;
            }
            ans += wt;
        }
        return ans;
    }
};