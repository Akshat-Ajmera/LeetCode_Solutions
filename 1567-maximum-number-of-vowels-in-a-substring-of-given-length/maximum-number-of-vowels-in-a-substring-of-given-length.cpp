class Solution {
private:
    bool vowel(char c) {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
public:
    int maxVowels(string s, int k) {
        int cnt=0, mxm=0, n=s.size();
        for(int i=0; i<k; i++) {
            if(vowel(s[i])) {
                cnt++;
            }
        }
        mxm = cnt;
        for(int i=1; i<=n-k; i++) {
            if(vowel(s[i-1])) {
                cnt--;
            }
            if(vowel(s[i+k-1])) {
                cnt++;
            }
            mxm = max(mxm,cnt);
        }
        return mxm;
    }
};