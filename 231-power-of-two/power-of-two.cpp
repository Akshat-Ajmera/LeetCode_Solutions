class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0) return false;
        int cnt = 0;
        for(int i=0; i<32; i++) if(n & (1 << i)) cnt++;
        return cnt == 1 ? true : false;
    }
};