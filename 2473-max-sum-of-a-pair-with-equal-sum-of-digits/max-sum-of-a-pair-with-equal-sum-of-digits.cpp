class Solution {
    int digSum(int num) {
        int ans = 0;
        while(num) {
            ans += (num % 10);
            num /= 10;
        }
        return ans;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size(), ans = -1, num1, num2;
        unordered_map<int, multiset<int>> mp;
        for(int i=0; i<n; i++) {
            mp[digSum(nums[i])].insert(-nums[i]);
        }
        for(auto &it : mp) {
            if(it.second.size() < 2) continue;
            auto it1 = it.second.begin();
            num1 = *it1;
            it1++;
            num2 = *it1;
            ans = max(ans, -1 * (num1 + num2));
        }
        return ans;
    }
};