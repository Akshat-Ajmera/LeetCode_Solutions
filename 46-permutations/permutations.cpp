class Solution {
private:
    void solve(vector<int> nums, vector<int> &v, vector<vector<int>> &ans) {
        if(v.size() == nums.size()) {
            ans.push_back(v);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == INT_MIN) continue;
            v.push_back(nums[i]);
            int temp = nums[i];
            nums[i] = INT_MIN;
            solve(nums, v, ans);
            nums[i] = temp;
            v.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> ans;
        solve(nums, v, ans);
        return ans;
    }
};