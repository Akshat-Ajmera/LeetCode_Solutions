class Solution {
public:
    string findDifferentBinaryString(vector<string> &v) {
        string ans;
        int n = v.size();
        for(int i=0; i<n; i++) {
            if(v[i][i] == '1') ans += '0';
            else ans += '1';
        }
        return ans;
    }
};