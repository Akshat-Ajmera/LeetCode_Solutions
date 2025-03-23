class Solution {
private:
    vector<int> divide(vector<int> &v, int lo, int hi) {
        if (lo == hi) return {v[lo]};
        int mid = lo + (hi - lo) / 2;
        vector<int> left = divide(v, lo, mid), right = divide(v, mid + 1, hi);
        return conquer(left, right);
    }
    vector<int> conquer(vector<int> &u, vector<int> &v) {
        vector<int> ans;
        int i = 0, j = 0;
        while (i < u.size() && j < v.size()) ans.push_back(u[i] < v[j] ? u[i++] : v[j++]);
        while (i < u.size()) ans.push_back(u[i++]);
        while (j < v.size()) ans.push_back(v[j++]);
        return ans;
    }
public:
    vector<int> sortArray(vector<int>& v) {
        return divide(v, 0, v.size() - 1);
    }
};