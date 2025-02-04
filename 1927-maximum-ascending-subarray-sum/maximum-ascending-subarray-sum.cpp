class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size(), ans = 0, mxm = 0, j = 0;
        if(n == 1) return nums[0];
        while(j < n) {
            while(j < n-1 && nums[j] < nums[j+1]) {
                mxm += nums[j];
                j++;
            }
            mxm += nums[j];
            ans = max(ans, mxm);
            mxm = 0;
            j++;
        }
        return ans;
    }
};