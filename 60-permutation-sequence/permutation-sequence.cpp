class Solution {
public:
    string getPermutation(int n, int k) {
        int fac = 1;
        vector<int> num;
        for(int i=1; i<n; i++) {
            fac *= i;
            num.push_back(i);
        }
        num.push_back(n);
        string ans = "";
        k--;
        while(true) {
            ans += to_string(num[k / fac]);
            num.erase(num.begin() + (k / fac));
            if(num.empty()) break;
            k %= fac;
            fac /= num.size();
        }
        return ans;
    }
};