class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> nse(n, n);
        vector<int> pse(n, -1);
        stack<int> stk;
        for(int i=n-1; i>=0; i--) {
            if(!stk.empty()) {
                while(!stk.empty() && h[i] <= h[stk.top()]) stk.pop();
                if(!stk.empty()) nse[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=0; i<n; i++) {
            if(!stk.empty()) {
                while(!stk.empty() && h[i] <= h[stk.top()]) stk.pop();
                if(!stk.empty()) pse[i] = stk.top();
            }
            stk.push(i);
        }
        for(int i=0; i<n; i++) {
            ans = max(ans, h[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
};