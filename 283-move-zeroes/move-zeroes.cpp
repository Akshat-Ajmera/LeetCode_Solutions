class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(), i=0, j=0;
        if(n==0 || n==1) {
            return;
        }
        while(i<n && j<n) {
            while(i<n && nums[i]) {
                i++;
            }
            while(j<n && !nums[j]) {
                j++;
            }
            if(i>=n || j>=n) {
                return;
            }
            if(i<j) {
                swap(nums[i], nums[j]);
            }
            j++;
        }
        return;
    }
};