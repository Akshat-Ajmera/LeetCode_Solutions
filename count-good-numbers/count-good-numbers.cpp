class Solution {
private:
    unsigned long long powMod(unsigned long long a, unsigned long long b, unsigned long long p) {  // power of large numbers using mod
        unsigned long long ans = 1;
        a %= p;
        while(b) {
            if(b & 1) {ans = (ans * a) % p;}
            a = (a * a) % p;
            b >>= 1;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        unsigned long long odd=n/2, even=(n/2)+(n%2), mod = 1e9+7;
        return (powMod(5,even,mod)*powMod(4,odd,mod))%mod;
    }
};