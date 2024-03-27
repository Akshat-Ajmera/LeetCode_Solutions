class Solution {
private:
    void buildSegTree(vector<long long> &v, vector<long long> &seg, int lo, int hi, int ind) {
        if(lo == hi) {
            seg[ind] = v[lo];
            return;
        }
        int mid = lo + ((hi - lo) / 2);
        buildSegTree(v, seg, lo, mid, (2*ind)+1);
        buildSegTree(v, seg, mid+1, hi, (2*ind)+2);
        seg[ind] = seg[(2*ind)+1] + seg[(2*ind)+2];
    }
    void updateSegTree(vector<long long> &seg, int lo, int hi, int ind, int pos, int val) {
        if(lo == hi) {
            seg[ind] += val;
            return;
        }
        int mid = lo + ((hi - lo) / 2);
        if(pos <= mid) updateSegTree(seg, lo, mid, (2*ind)+1, pos, val);
        else updateSegTree(seg, mid+1, hi, (2*ind)+2, pos, val);
        seg[ind] = seg[(2*ind)+1] + seg[(2*ind)+2];
    }
    long long querySegTree(vector<long long> &seg, int a, int b, int lo, int hi, int ind) {
        if(a > hi || b < lo) return 0;
        if(a <= lo && b >= hi) return seg[ind];
        int mid = lo + ((hi - lo) / 2);
        long long e = querySegTree(seg, a, b, lo, mid, (2*ind)+1);
        long long f = querySegTree(seg, a, b, mid+1, hi, (2*ind)+2);
        return (e + f);
    }
    long long cntInv(vector<int> &v) {
        int n = v.size();
        long long ans = 0;
        vector<long long> freq(n, 0), seg(4*n, 0);
        for(int i=0; i<n; i++) freq[v[i]]++;
        buildSegTree(freq, seg, 0, n-1, 0);
        for(int i=0; i<n; i++) {
            updateSegTree(seg, 0, n-1, 0, v[i], -1);
            ans += querySegTree(seg, 0, v[i], 0, n-1, 0);
        }
        return ans;
    }
public:
    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        long long locInv = 0, glbInv = 0;
        for(int i=0; i<n-1; i++) {
            if(nums[i] > nums[i+1]) locInv++;
        }
        glbInv = cntInv(nums);
        return (glbInv == locInv);
    }
};