class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size(), i = 0, j = 0, ans = 0;
        map<char, int> mp;
        while(j < n) {
            if(mp.find(s[j]) != mp.end()) i = max(i, mp[s[j]] + 1);
            mp[s[j]] = j;
            j++;
            ans = max(ans, j - i);
        }
        return ans;
    }
};