class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unsigned long long ans = 0, num1, num2;
        multiset<unsigned long long> st;
        for(auto &it : nums) st.insert(it);
        while(st.size() >= 2) {
            auto it1 = st.begin();
            auto it2= it1;
            it2++;
            num1 = *it1;
            num2 = *it2;
            if(num1 >= k) return ans;
            st.erase(it1);
            st.erase(it2);
            st.insert(((2 * min(num1, num2)) + max(num1, num2)));
            ans++;
        }
        return ans;
    }
};