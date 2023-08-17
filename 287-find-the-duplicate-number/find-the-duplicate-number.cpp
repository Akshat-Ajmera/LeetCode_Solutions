class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i=0; i<n; i++) {
            if(!st.count(nums[i])) {
                st.insert(nums[i]);
            }
            else {
                return nums[i];
            }
        }
        return -1;
    }
};