class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int i = 0, j = 0, ans = 1, n = nums.size();
        while(j < n) {
            while((j+1 < n) && (nums[j] < nums[j+1])) j++;
            ans = max(ans, j-i+1);
            j++;
            i = j;
        }
        reverse(nums.begin(), nums.end());
        i = 0, j = 0;
        while(j < n) {
            while(j+1 < n && nums[j] < nums[j+1]) j++;
            ans = max(ans, j-i+1);
            j++;
            i = j;
        }
        return ans;
    }
};