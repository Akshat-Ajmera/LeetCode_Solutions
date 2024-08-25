class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size(), i = 0, ans = 0;
        if(!n || n < k) return 0;
        vector<int> freq(26, 0);
        for(auto &ch : s) freq[ch - 'a']++;
        while(i < n && freq[s[i]-'a'] >= k) i++;
        if(i == n) return n;
        ans = max(ans, longestSubstring(s.substr(0, i), k));
        ans = max(ans, longestSubstring(s.substr(i+1), k));
        return ans;
    }
};
