class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        int n = s.size();
        string ans;
        for(int i=0; i<numRows; i++) {
            int j = i, last = -1;
            bool f = true;
            while(j < n) {
                if(j != last) ans += s[j];
                last = j;
                if(f) j += (2*(numRows-i-1));
                else j += (2*i);
                f = !f;
            }
        }
        return ans;
    }
};