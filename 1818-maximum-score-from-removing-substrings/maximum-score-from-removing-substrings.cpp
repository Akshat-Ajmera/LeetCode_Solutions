class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string match = (x >= y) ? "ab" : "ba";
        int ans = 0;
        stack<int> stk;
        stk.push(s[0]);
        for(int i=1; i<s.size(); i++) {
            if(!stk.empty() && stk.top() == match[0] && s[i] == match[1]) {
                stk.pop();
                ans += max(x, y);
            }
            else {
                stk.push(s[i]);
            }
        }
        s = "";
        while(!stk.empty()) {
            s += stk.top();
            stk.pop();
        }
        reverse(s.begin(), s.end());
        swap(match[0], match[1]);
        stk.push(s[0]);
        for(int i=1; i<s.size(); i++) {
            if(!stk.empty() && stk.top() == match[0] && s[i] == match[1]) {
                stk.pop();
                ans += min(x, y);
            }
            else {
                stk.push(s[i]);
            }
        }
        return ans;
    }
};