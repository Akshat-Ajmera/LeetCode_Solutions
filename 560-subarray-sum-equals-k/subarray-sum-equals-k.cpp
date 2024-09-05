class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), ans = 0, pre = 0;
        unordered_map<int, int> mp;
        multiset<int> st;
        for(int i=0; i<n; i++) {
            pre += nums[i];
            if(pre == k) ans++;
            if(mp.count(pre - k)) ans += mp[pre - k];
            mp[pre]++;
        }
        return ans;
    }
};