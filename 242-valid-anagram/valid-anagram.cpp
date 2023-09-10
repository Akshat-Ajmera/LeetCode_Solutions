class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1 != n2) {
            return false;
        }
        vector<int> v(26,0);
        for(int i=0; i<n1; i++) {
            v[s[i]-'a']++;
        }
        for(int i=0; i<n2; i++) {
            v[t[i]-'a']--;
        }
        for(int i=0; i<26; i++) {
            if(v[i]) {
                return false;
            }
        }
        return true;
    }
};