class Solution {
private:
    vector<int> merge_sort(vector<int> &v, int lo, int hi) {
        if(lo == hi) {
            return {v[lo]};
        }
        int mid = lo+(hi-lo)/2;
        vector<int> u = merge_sort(v, lo, mid);
        vector<int> w = merge_sort(v, mid+1, hi);
        int u_siz = u.size(), w_siz = w.size(), i = 0, j = 0, k = 0;
        vector<int> res(u_siz + w_siz);
        while((i < u_siz) && (j < w_siz)) {
            if(u[i] < w[j]) {
                res[k] = u[i];
                i++;
            }
            else {
                res[k] = w[j];
                j++;
            }
            k++;
        }
        while(i < u_siz) {
            res[k] = u[i];
            i++;
            k++;
        }
        while(j < w_siz) {
            res[k] = w[j];
            j++;
            k++;
        }
        return res;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        return merge_sort(nums, 0, nums.size()-1);
    }
};