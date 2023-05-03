class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        vector<vector<int>> ans;
        vector<int> ans1, ans2;
        for(int i : nums1) {
            s1.insert(i);
        }
        for(int j : nums2) {
            s2.insert(j);
        }
        for(int p : nums1) {
            if(s2.find(p) == s2.end()) {
                ans1.push_back(p);
                s2.insert(p);
            }
        }
        for(int q : nums2) {
            if(s1.find(q) == s1.end()) {
                ans2.push_back(q);
                s1.insert(q);
            }
        }
        ans.push_back(ans1);
        ans.push_back(ans2);
        return ans;
    }
};