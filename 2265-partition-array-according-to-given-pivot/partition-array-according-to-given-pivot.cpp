class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size(), cnt = 0;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(nums[i] == pivot) cnt++;
            if(nums[i] < pivot) ans.push_back(nums[i]);
        }
        for(int i=0; i<cnt; i++) ans.push_back(pivot);
        for(int i=0; i<n; i++) {
            if(nums[i] > pivot) ans.push_back(nums[i]);
        }
        return ans;
    }
};