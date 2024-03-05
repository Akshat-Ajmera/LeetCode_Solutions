class NumArray {
private:
    void buildSegTree(vector<int> &v, vector<int> &seg, int lo, int hi, int ind) {
        if(lo == hi) {
            seg[ind] = v[lo];
            return;
        }
        int mid = (lo + ((hi - lo) / 2));
        buildSegTree(v, seg, lo, mid, (2*ind)+1);
        buildSegTree(v, seg, mid+1, hi, (2*ind)+2);
        seg[ind] = seg[(2*ind)+1] + seg[(2*ind)+2]; 
    }
    void updateSegTree(vector<int> &seg, int lo, int hi, int pos, int val, int ind) {
        if(lo == hi) {
            seg[ind] = val;
            return;
        }
        int mid = (lo + ((hi - lo) / 2));
        if(pos <= mid) updateSegTree(seg, lo, mid, pos, val, (2*ind)+1);
        else updateSegTree(seg, mid+1, hi, pos, val, (2*ind)+2);
        seg[ind] = seg[(2*ind)+1] + seg[(2*ind)+2];
    }
    int querySegTree(vector<int> &seg, int a, int b, int lo, int hi, int ind) {
        if(a>hi || b<lo) return 0;
        if(a<=lo && b>=hi) return seg[ind];
        int mid = (lo + ((hi - lo) / 2));
        int e = querySegTree(seg, a, b, lo, mid, (2*ind)+1);
        int f = querySegTree(seg, a, b, mid+1, hi, (2*ind)+2);
        return e + f;
    }
public:
    vector<int> seg, nums;
    NumArray(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size();
        seg.resize(4*n, 0);
        buildSegTree(nums, seg, 0, n-1, 0);
    }
    void update(int index, int val) {
        updateSegTree(seg, 0, nums.size()-1, index, val, 0);
    }
    int sumRange(int left, int right) {
        return querySegTree(seg, left, right, 0, nums.size()-1, 0);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */