class Solution {
private:
    int solve(int num) {
        int tot = 0;
        set<int> st;
        for(int i=1; i*i<=num; i++) {
            if(!(num % i)) {
                if((i * i == num)) st.insert(i);
                else {
                    st.insert(i);
                    st.insert(num / i);
                }
            }
        }
        if(st.size() != 4) return 0;
        for(auto &it : st) tot += it;
        return tot;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto &num : nums) ans += solve(num);
        return ans;
    }
};