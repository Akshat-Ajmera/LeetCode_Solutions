class Solution {
public:
    string mergeAlternately(string w1, string w2) {
        string ans = "";
        int i = 0, j, n1 = w1.size(), n2 = w2.size();
        for(i=0; i<min(n1,n2); i++) {
            ans += w1[i];
            ans += w2[i];
        }
        for(; i<n1; i++) {
            ans += w1[i];
        }
        for(; i<n2; i++) {
            ans += w2[i];
        }
        return ans;
    }
};