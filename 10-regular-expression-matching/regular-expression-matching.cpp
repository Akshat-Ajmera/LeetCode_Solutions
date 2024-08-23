class Solution {
private:
    bool solve(string &str, string &ptn, int n, int m) {
        if(n < 0 && m < 0) return true;
        if(n < 0) {
            if(ptn[m] != '*') return false;
            else return solve(str, ptn, n, m-2);
        }
        if(m < 0) return false;
        bool ans = false;
        if(ptn[m] == '.' || ptn[m] == str[n]) ans = solve(str, ptn, n-1, m-1);
        else if(ptn[m] == '*') {
            if(ptn[m-1] == '.' || ptn[m-1] == str[n]) ans = solve(str, ptn, n-1, m) || solve(str, ptn, n-1, m-2);
            ans = ans || solve(str, ptn, n, m-2);
        }
        return ans;
    }
public:
    bool isMatch(string str, string ptn) {
        int n = str.size(), m = ptn.size();
        return solve(str, ptn, n-1, m-1);
    }
};