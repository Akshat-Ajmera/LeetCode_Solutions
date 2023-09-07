class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n);
        stack<int> st;
        unordered_map<int,int> mp;
        mp.insert({nums2[m-1],-1});
        st.push(nums2[m-1]);
        for(int i=m-2; i>=0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            if(st.empty()) {
                mp.insert({nums2[i],-1});
            }
            else {
                mp.insert({nums2[i],st.top()});
            }
            st.push(nums2[i]);
        }
        for(int i=0; i<n; i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};