class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        int ans = -1;
        for(auto it : nums) {
            if(st.find(-it) != st.end()) {
                ans = max(ans, abs(it));
            }
            st.insert(it);
        }
        return ans;
    }
};