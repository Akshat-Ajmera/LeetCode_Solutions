class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        int n = nums2.size(), n1 = nums1.size();
        vector<int> ans(n1);
        map<int, int> mp;
        for(int i=n-1; i>=0; i--) {
            while(!stk.empty() && (stk.top() <= nums2[i])) stk.pop();
            if(stk.empty()) mp[nums2[i]] = -1;
            else mp[nums2[i]] = stk.top();
            stk.push(nums2[i]);
        }
        for(int i=0; i<n1; i++) ans[i] = mp[nums1[i]];
        return ans;
    }
};