class Solution {
public:
    long long countBadPairs(vector<int>& v) {
        long long ans = 0, n = v.size();
        map<long long, long long> mp; 
        for(int i=0; i<n; i++) mp[i - v[i]]++;
        for(auto &it : mp) ans += it.second * (n - it.second);
        ans /= 2;
        return ans;
    }
};