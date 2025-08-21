class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, i = 0, j = 0;
        while(j < nums.size()) {
            while(j < nums.size() && nums[j]) j++;
            i = j;
            while(j < nums.size() && !nums[j]) j++;
            j--;
            ans += ((j - i + 1) * (j - i + 2)) / 2;
            j++;
            i = j;
        }
        return ans;
    }
};