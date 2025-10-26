class Solution {
private:
    void solve(string temp, vector<string> &ans, int n, int open, int close) {
        if(!open && !close && temp.size() == 2*n) {
            ans.push_back(temp);
            return;
        }
        for(int i=1; i<=close-open; i++) {
            temp.push_back(')');
            solve(temp, ans, n, open, close-i);
            temp.pop_back();
        }
        for(int i=1; i<=open; i++) {
            temp.push_back('(');
            solve(temp, ans, n, open-i, close);
            temp.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> ans;
        solve(temp, ans, n, n, n);
        return ans;
    }
};