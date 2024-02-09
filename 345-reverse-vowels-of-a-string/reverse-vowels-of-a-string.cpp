class Solution {
private:
    bool check(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U');
    }
    void swap(int i, int j, string &s) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
public:
    string reverseVowels(string s) {
        int n = s.size(), i = 0, j = n-1;
        while(i<n && j>=0 && i<j) {
            while(i<n && !check(s[i])) {
                i++;
            }
            while(j>=0 && !check(s[j])) {
                j--;
            }
            if(i<j && check(s[i]) && check(s[j])) {
                swap(i,j,s);
                i++;
                j--;
            }
        }
        return s;
    }
};