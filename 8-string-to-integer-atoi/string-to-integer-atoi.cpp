class Solution {
private:
    bool isChar(char c) {
        return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '.');
    }
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    }
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long ans = 0;
        bool sign = false;
        while(i < n && s[i] == ' ') i++;
        if(isChar(s[i])) return ans;
        if(i < n && s[i] == '-') {
            sign = true;
            i++;
        }
        else if(i < n && s[i] == '+') i++;
        if(isChar(s[i])) return ans;
        while(i < n && s[i] == '0') i++;
        if(isChar(s[i])) return ans;
        for(int j=i; j<n; j++) {
            if(isChar(s[j]) || (s[j] == '-') || (s[j] == '+') || (s[j] == ' ')) {
                if(sign) {
                    if(-ans <= INT_MIN) return INT_MIN;
                    else return -ans;
                }
                else {
                    if(ans >= INT_MAX) return INT_MAX;
                    else return ans;
                }
            }
            ans = (10 * ans) + (s[j] - '0');
            if(sign) {
                if(-ans <= INT_MIN) return INT_MIN;
            }
            else {
                if(ans >= INT_MAX) return INT_MAX;
            }
        }
        if(sign) ans *= -1;
        if(ans >= INT_MAX) ans = INT_MAX;
        if(ans <= INT_MIN) ans = INT_MIN;
        return ans;
    }
};