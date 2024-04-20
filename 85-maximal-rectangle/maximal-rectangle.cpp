class Solution {
private:
    void solve(vector<int> &h, vector<int> &nsi, vector<int> &psi) {
        int n = h.size();
        stack<int> stk;
        for(int i=0; i<n; i++) {
            while(!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
            if(stk.empty()) psi[i] = -1;
            else psi[i] = stk.top();
            stk.push(i);
        }
        while(!stk.empty()) stk.pop();
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && h[stk.top()] >= h[i]) stk.pop();
            if(stk.empty()) nsi[i] = n;
            else nsi[i] = stk.top();
            stk.push(i);
        }
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> height(n, 0), nsi(n), psi(n);
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }
            solve(height, nsi, psi);
            for(int j=0; j<n; j++) {
                ans = max(ans, height[j] * (nsi[j] - psi[j] - 1));
            }
        }
        return ans;
    }
};