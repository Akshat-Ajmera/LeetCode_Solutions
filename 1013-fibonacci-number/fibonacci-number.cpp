class Solution {
private:
    int fib1(int n, vector<int> &f) {
        if(n<=1) {
            f[n] = n;
            return f[n];
        }
        if(f[n] != -1) {
            return f[n];
        }
        return f[n] = fib1(n-1,f) + fib1(n-2,f);
    }
public:
    int fib(int n) {
        vector<int> f(31,-1);
        fib1(n,f);
        for(int i=0; i<31; i++) {
            cout << f[i] << " ";
        }
        return fib1(n,f);
    }
};