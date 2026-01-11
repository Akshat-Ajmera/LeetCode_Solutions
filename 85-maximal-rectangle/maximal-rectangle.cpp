class Solution {
private:
    int solve(vector<int> &v) {
        int n = v.size(), ans = 0;
        vector<int> nse(n, n), pse(n, -1);
        stack<int> stk;
        for(int i=n-1; i>=0; i--) {
            if(!stk.empty()) {
                while(!stk.empty() && v[stk.top()] >= v[i]) stk.pop();
                if(!stk.empty()) nse[i] = stk.top();
            }
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=0; i<n; i++) {
            if(!stk.empty()) {
                while(!stk.empty() && v[stk.top()] >= v[i]) stk.pop();
                if(!stk.empty()) pse[i] = stk.top();
            }
            stk.push(i);
        }
        for(int i=0; i<n; i++) {
            ans = max(ans, v[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        vector<int> v(n);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!(matrix[i][j] - '0')) v[j] = 0;
                else v[j]++;
            }
            ans = max(ans, solve(v));
        }
        return ans;
    }
};