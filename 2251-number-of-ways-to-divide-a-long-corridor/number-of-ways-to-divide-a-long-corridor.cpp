class Solution {
private:
    int modMul(int a, int b) {
        int mod = 1e9 + 7;
        return (1LL * a * b) % mod;
    }
public:
    int numberOfWays(string corridor) {
    int ans = 1, s_cnt = 0, last = 0;
        vector<int> v;
        for(char ch : corridor) s_cnt = ch == 'S' ? s_cnt + 1 : s_cnt;
        if(!s_cnt || s_cnt % 2) return 0;
        if(s_cnt == 2) return 1;
        s_cnt = 0;
        for(int i=0; i<corridor.size(); i++) {
            if(corridor[i] == 'P') continue;
            s_cnt++;
            if(s_cnt == 1) v.push_back(i - last);
            else if(s_cnt == 2) {
                s_cnt = 0;
                last = i;
            }
        }
        for(int i=1; i<v.size(); i++) ans = modMul(ans, v[i]);
        return ans;
    }
};