class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), ans = 1, mxm = 1;
        if(!n) return 0;
        set<int> st;
        for(auto it : nums) st.insert(it);
        for(auto it : st) {
            if(st.find(it-1) != st.end()) continue;
            else {
                int num = it + 1;
                while(st.find(num) != st.end()) {
                    mxm++;
                    num++;
                }
                ans = max(ans, mxm);
                mxm = 1;
            }
        }
        return ans;
    }
};