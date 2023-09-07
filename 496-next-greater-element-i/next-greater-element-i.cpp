class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            stack<int> st;
            if(nums2[m-1] == nums1[i]) {
                ans[i] = -1;
                continue;
            }
            st.push(nums2[m-1]);
            for(int j=m-2; j>=0; j--) {
                while(!st.empty() && st.top() <= nums2[j]) {
                    st.pop();
                }
                if(nums1[i] == nums2[j]) {
                    if(st.empty()) {
                        ans[i] = -1;
                    }
                    else {
                        ans[i] = st.top();
                    }
                    break;
                }
                st.push(nums2[j]);
            }
        }
        return ans;
    }
};