class Solution {
private:
    vector<int> divide(vector<int> &vec, int lo, int hi) {
        if(lo == hi) return {vec[lo]};
        int mid = (lo + ((hi - lo) / 2));
        vector<int> u = divide (vec, lo, mid), v = divide (vec, mid + 1, hi);
        return conquer(u, v);
    }
    vector<int> conquer(vector<int> &u, vector<int> &v) {
        int m = u.size(), n = v.size(), i = 0, j = 0, k = 0;
        vector<int> ans(m + n);
        while(i < m && j < n) {
            if(u[i] < v[j]) {
                ans[k] = u[i];
                i++;
            }
            else {
                ans[k] = v[j];
                j++;
            }
            k++;
        }
        while(i < m) {
            ans[k] = u[i];
            i++;
            k++;
        }
        while(j < n) {
            ans[k] = v[j];
            j++;
            k++;
        }
        return ans;
    }
public:
    vector<int> sortArray(vector<int>& v) {
        int n = v.size();
        return divide(v, 0, n-1);
    }
};