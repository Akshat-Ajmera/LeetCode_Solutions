class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size(), ans = 0;
        vector<int> nextS(n), prevS(n);
        stack<int> st1, st2;
        for(int i=0; i<n; i++) {
            while(!st1.empty() && h[i] <= h[st1.top()]) {
                st1.pop();
            }
            if(st1.empty()) {
                prevS[i] = -1;
            }
            else {
                prevS[i] = st1.top();
            }
            st1.push(i);
        }
        for(int i=n-1; i>=0; i--) {
            while(!st2.empty() && h[i] <= h[st2.top()]) {
                st2.pop();
            }
            if(st2.empty()) {
                nextS[i] = n;
            }
            else {
                nextS[i] = st2.top();
            }
            st2.push(i);
        }
        for(int i=0; i<n; i++) {
            cout << prevS[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++) {
            cout << nextS[i] << " ";
        }
        cout << endl;
        for(int i=0; i<n; i++) {
            ans = max(ans, (h[i]*(nextS[i]-prevS[i]-1)));
        }
        return ans;
    }
};