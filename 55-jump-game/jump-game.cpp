class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), canreach = 0;
        for(int i=0; i<n; i++) {
            if(i <= canreach) {
                canreach = max(canreach, nums[i] + i);
                if(canreach >= n-1) {
                    return true;
                }
            }
            else {
                return false;
            }
        }
        return false;
    }
};