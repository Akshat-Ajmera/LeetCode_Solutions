class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans = 0;
        set<int> st;
        for(auto it : nums) st.insert(it);
        ans = st.size();
        auto it = st.begin();
        for(int i=0; i<ans; i++) {
            nums[i] = *it;
            it++;
        }
        return ans;
    }
};