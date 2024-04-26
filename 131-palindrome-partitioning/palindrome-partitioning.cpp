class Solution {
private:
    bool check(int ind2, int ind1, string &str) {
        int n = ind2 - ind1 + 1;
        for(int i=0; i<(n/2); i++) {
            if(str[ind1 + i] != str[ind2 - i]) return false;
        }
        return true;
    }
    void solve(int ind, string &s, vector<string> &temp, vector<vector<string>> &ans) {
        if(ind >= s.size()) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<s.size(); i++) {
            if(!check(i, ind, s)) continue;
            string temp_str;
            for(int j=ind; j<=i; j++) temp_str += s[j];
            temp.push_back(temp_str);
            solve(i+1, s, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};