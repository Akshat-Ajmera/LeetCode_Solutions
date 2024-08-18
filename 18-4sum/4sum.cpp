class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        long long sum;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0, j, k, l;
        while(i < n) {
            j = i+1;
            while(j < n) {
                k = j+1, l = n-1;
                while(k < n && l > j && k < l) {
                    sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l]; 
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while(k+1 < n && nums[k] == nums[k+1]) k++;
                        k++;
                        while(l > j+1 && nums[l] == nums[l-1]) l--;
                        l--;
                    }
                    else if(sum < target) {
                        while(k+1 < n && nums[k] == nums[k+1]) k++;
                        k++;
                    }
                    else {
                        while(l > j+1 && nums[l] == nums[l-1]) l--;
                        l--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
                j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
            i++;
        }
        return ans;
    }
};