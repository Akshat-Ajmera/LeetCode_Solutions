class Solution {
private:
    int modPow(long long a, long long b, int p = 1e9 + 7) {
        int ans = 1;
        a %= p;
        while(b) {
            if(b & 1) {ans = (ans * a) % p;}
            a = (a * a) % p;
            b >>= 1;
        }
        return ans;
    }
    int modAdd(int a, unsigned long long b, int p = 1e9 + 7) {
        return (((a % p) + (b % p)) % p);
    }
public:
    int numSubseq(vector<int>& nums, int tgt) {
        int mod = 1e9 + 7, n = nums.size(), i = 0, j = n-1, ans = 0;
        sort(nums.begin(), nums.end());
        while(i <= j) {
            if(nums[i] + nums[j] <= tgt) {
                ans = modAdd(ans, modPow(2, j-i));
                i++;
            }
            else {
                j--;
            }
        }
        return ans;
    }
};