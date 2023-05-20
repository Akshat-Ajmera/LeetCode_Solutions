class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size()/2;
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int c = ++mp[nums[i]];
            if(c>n) {
                return nums[i];
            }
        }
        return -1;
    }
};