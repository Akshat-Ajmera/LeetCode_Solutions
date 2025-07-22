class Solution {
public:
    int maximumUniqueSubarray(vector<int>& v) {
        int l = 0, r = 0, ans = 0, mxm = 0;
        set<int> st;
        while(r < v.size()) {
            if(!st.count(v[r])) {
                st.insert(v[r]);
                mxm += v[r];
                r++;
            }
            else {
                while(st.count(v[r])) {
                    st.erase(v[l]);
                    mxm -= v[l];
                    l++;
                }
            }
            ans = max(ans, mxm);
        }
        return ans;
    }
};