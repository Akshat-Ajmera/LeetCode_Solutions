class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1) return "";
        int n1 = str1.size(), n2 = str2.size(), n = __gcd(n1, n2);
        string ans = "";
        for(int i=0; i<n; i++) ans += str1[i];
        return ans;
    }
};