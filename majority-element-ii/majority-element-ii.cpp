class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int m = nums.size();
        int n = nums.size()/3;
        unordered_map<int, int> mp;
        unordered_set<int> st;
        for(int i=0; i<m; i++) {
            int c = ++mp[nums[i]];
            if(c>n) {
                st.insert(nums[i]);
            }
        }
        for(auto it = st.begin(); it != st.end(); it++) {
            ans.push_back(*it);
        }
        return ans;
    }
};