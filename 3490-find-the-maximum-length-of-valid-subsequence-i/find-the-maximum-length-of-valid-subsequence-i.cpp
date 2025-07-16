class Solution {
public:
    int maximumLength(vector<int>& v) {
        int n = v.size(), a = 0, b = 0, c = 1, d = 1;
        bool flag = v[0] % 2;
        for(int i=0; i<n; i++) {
            if(v[i] % 2) a++;
            else b++;
        }
        for(int i=1; i<n; i++) {
            if(flag && !(v[i] % 2)) {
                c++;
                flag = false;
            }
            else if(!flag && (v[i] % 2)) {
                c++;
                flag = true;
            }
        }
        flag = v[n-1] % 2;
        for(int i=n-2; i>=0; i--) {
            if(flag && !(v[i] % 2)) {
                d++;
                flag = false;
            }
            else if(!flag && (v[i] % 2)) {
                d++;
                flag = true;
            }
        }
        return max({a, b, c, d});
    }
};