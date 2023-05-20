class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            int c = ++mp[nums[i]];
            if(c>(nums.size()/2)) {
                return nums[i];
            }
        }
        return -1;
    }
};