class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans = 0, cnt = 0, negSum = INT_MIN;
        set<int> st;
        for(int it : nums) {
            if(it < 0) {
                cnt++;
                negSum = max(negSum, it);
                continue;
            }
            if(st.count(it)) continue;
            ans += it;
            st.insert(it);
        }
        if(cnt == nums.size()) return negSum;
        return ans;
    }
};