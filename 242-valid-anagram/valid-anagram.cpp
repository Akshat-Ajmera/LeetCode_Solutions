class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 != n2) {
            return false;
        }
        map<char,int> mp;
        for(int i=0; i<n1; i++) {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for(auto it : mp) {
            if(it.second) {
                return false;
            }
        }
        return true;
    }
};