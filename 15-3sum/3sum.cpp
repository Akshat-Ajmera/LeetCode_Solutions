class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            int j = i+1, k = n-1;
            while(j < n && k >= 0 && j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> v = {nums[i], nums[j], nums[k]};
                    ans.push_back(v);
                    while(j+1 < n && nums[j] == nums[j+1]) j++;
                    if(j+1 < n) j++;
                    while(k >= 1 && nums[k] == nums[k-1]) k--;
                    if(k >= 1) k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0) {
                    while(j+1 < n && nums[j] == nums[j+1]) j++;
                    if(j+1 < n) j++;
                }
                else {
                    while(k >= 1 && nums[k] == nums[k-1]) k--;
                    if(k >= 1) k--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};