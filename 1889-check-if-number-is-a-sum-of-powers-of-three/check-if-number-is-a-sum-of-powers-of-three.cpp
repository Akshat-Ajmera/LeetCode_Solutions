class Solution {
public:
    bool checkPowersOfThree(int n) {
        int num = 1;
        while(num < n) {
            num *= 3;
            if(num == n) return true;
        }
        num /= 3;
        while(num) {
            if(n >= num) {
                n -= num;
                if(n >= num) return false;
            }
            num /= 3;
        }
        return true;
    }
};